/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/03 00:47:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
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

void BitcoinExchange::addEntry(std::string &str) {
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
	while (std::getline(infile, line)) {
		int32_t year, month, day;
		float	rate;
		
		if (4 != sscanf(line.c_str(), "%d-%d-%d,%f", &year, &month, &day, &rate))
			throw std::runtime_error("error: database/data.csv: invalid file");
		printf("%d   %d   %d   =>   %f\n", year, month, day, rate);
	}
}

/* ************************************************************************** */

/* GETTERS ****************************************************************** */

/* EXCEPTIONS *************************************************************** */
