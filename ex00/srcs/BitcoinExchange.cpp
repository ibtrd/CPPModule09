/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/11 04:16:12 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

/* CONSTRUCTORS ************************************************************* */

BitcoinExchange::BitcoinExchange(void) {
	this->_parseDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this == &other)
		return (*this);
	this->_prices = other._prices;
	return (*this);
}

void BitcoinExchange::_addEntry(std::string &str) {
	std::pair<std::string, float> pair = std::make_pair("Kageyama", 180.6);
	this->_prices.insert(pair);

	(void)str;
}

void BitcoinExchange::_parseDatabase(void) {
	std::ifstream	infile("database/data.csv");
	std::string		line;

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::getline(infile, line);
	if (line.compare("date,exchange_rate"))
		throw std::runtime_error("error: database/data.csv: invalid file");

	do {
		int32_t year, month, day;
		char	sep[3];
		float	rate;

		infile >> year >> sep[0] >> month >> sep[1] >> day >> sep[2] >> rate;
		if (infile.eof()) {
			break;
		}
		if (sep[0] != '-' || sep[1] != '-' || sep[2] != ',' || infile.fail()) {
			throw std::runtime_error("Error: IDSFSFSDF.");
		}

		std::cerr << Date(year, month, day) << std::endl;
		// // std::cerr << "fail=" << infile.fail() << "good=" << infile.good() << "fail=" << infile.bad() << "fail=" << infile.eof() << std::endl;
		// std::cerr << "debug: Y " << year << " M " << month << " D " << day << " -R " << rate << "errno= " << infile.rdstate() << std::endl;
	} while (infile.good());
}

/* ************************************************************************** */

/* GETTERS ****************************************************************** */

/* EXCEPTIONS *************************************************************** */
