/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 21:02:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* CONSTRUCTORS ************************************************************* */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this == &other)
		return (*this);
	this->_prices = other.prices;
	return (*this);
}

/* GETTERS ****************************************************************** */

/* EXCEPTIONS *************************************************************** */

/* ************************************************************************** */