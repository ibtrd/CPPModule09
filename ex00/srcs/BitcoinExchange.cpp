/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/20 23:54:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

#include "BitcoinExchange.hpp"

/* CONSTRUCTORS ************************************************************* */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::BitcoinExchange(const std::string &path) {
	this->_parseDatabase(path);
}

BitcoinExchange::~BitcoinExchange(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this == &other)
		return (*this);
	this->_prices = other._prices;
	return (*this);
}

/* ************************************************************************** */

void BitcoinExchange::_parseDatabase(const std::string &path) {
	std::ifstream	infile(path.c_str());
	std::string		line;

	if (!infile.is_open())
		throw InvalidDatabaseException();
	std::getline(infile, line);
	if (line.compare("date,exchange_rate"))
		throw InvalidDatabaseException();
	do {
		int32_t year, month, day;
		char	sep[3];
		float	rate;

		infile >> year >> sep[0] >> month >> sep[1] >> day >> sep[2] >> rate;
		if (infile.eof()) {
			break;
		}
		if (sep[0] != '-' || sep[1] != '-' || sep[2] != ',' || infile.fail()) {
			throw InvalidDatabaseException();
		}
		try {
			Date	date(year, month, day);
			this->_prices[date] = rate;
		} catch (std::exception &e) {
			throw InvalidDatabaseException();
		}
	} while (infile.good());
}

int8_t	BitcoinExchange::parseQueryFile(const std::string &path) const {
	std::ifstream	infile(path.c_str());
	std::string		line;

	if (!infile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return (-1);
	}
	std::getline(infile, line);
	if (line.compare("date | value")) {
		std::cout << "Error: invalid input file." << std::endl;
		return (-1);
	}

	while (!std::getline(infile, line).eof()) {
		if (line.size() == 0) {
			continue;
		}
		this->_evaluateQuery(line);
	}
	return (0);
}

void	BitcoinExchange::_evaluateQuery(const std::string &str) const {
	const std::string::size_type	n = str.find(" | ");
	if (std::string::npos == n) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}

	Date	date;
	try {
		date = Date(str.substr(0, n));
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
	
	float				bitcoins;
	std::stringstream	ss(str);
	ss.ignore(n + 3);
	ss >> bitcoins;

	if (!ss.eof()) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	if (bitcoins > 1000) {
		std::cout << "Error: too large a number" << std::endl;
		return ;
	} else if (bitcoins < 0) {
		std::cout << "Error: negative number" << std::endl;
		return ;	
	}

	std::map<Date, float>::const_iterator 	rate = this->_prices.upper_bound(date);
	if (rate == this->_prices.begin()) {
		std::cout << "Error: bad input => " << str << std::endl;
	} else {
		--rate;
		std::cout << date << " => " << bitcoins << " = " << (rate->second * bitcoins) << std::endl;
	}
}

/* EXCEPTIONS *************************************************************** */

const char* BitcoinExchange::InvalidDatabaseException::what(void) const throw() {
	return ("Invalid database");
}
