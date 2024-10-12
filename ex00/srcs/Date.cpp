/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:16:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/12 20:48:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iomanip>

#include "Date.hpp"

/* CONSTRUCTORS ************************************************************* */

Date::Date(void) {
	_year = 0;
	_month = 0;
	_day = 0;
}

Date::Date(const Date &other) {
	*this = other;
}

Date::Date(int32_t year, int32_t month, int32_t day) {
	this->_year = year;
	this->_month = month;
	this->_day = day;
	if (this->isValidDate() == false) {
		throw Date::InvalidDateException();
	};
}

Date::Date(const std::string &string) {
	std::stringstream ss(string);
	char sep[2];

	ss >> this->_year >> sep[0] >> this->_month >> sep[1] >> this->_day;
	if (sep[0] != '-' || sep[1] != '-' || this->isValidDate() == false) {
		throw Date::InvalidDateException();
	};
}

Date::~Date(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Date	&Date::operator=(const Date &other)
{
	if (this == &other)
		return (*this);
	this->_year = other._year;
	this->_month = other._month;
	this->_day = other._day;
	return (*this);
}

Date	Date::operator++(int) {
	Date	post(*this);

	++(*this);
	return (post);
}

Date	&Date::operator++(void) {
	this->_day++;
	if (false == this->isValidDate()) {
		this->_month++;
		this->_day = 1;
		if (false == this->isValidDate()) {
			this->_year++;
			this->_month = 1;
		}
	}
	return (*this);
}

bool	Date::operator==(const Date &other) const {
	return (this->_year == other._year && this->_month == other._month && this->_day == other._day);
}

bool	Date::operator!=(const Date &other) const {
	return (this->_year != other._year || this->_month != other._month || this->_day != other._day);
}

bool	Date::operator<(const Date &other) const {
	if (this->_year != other._year) {
		return (this->_year < other._year);
	}
	if (this->_month != other._month) {
		return (this->_month < other._month);
	}
	return (this->_day < other._day);
}

/* ************************************************************************** */

bool	Date::isValidDate(void) const {
	const int32_t daysInMonth[] = { 31, 28 + Date::isLeapYear(this->_year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (this->_year < 0
		|| this->_month < 1 || this->_month > 12
		|| this->_day < 0 || this->_day > daysInMonth[this->_month - 1]) {
			return (false);
	}
	return (true);
}

std::string	Date::toString(void) const {
	std::stringstream	str;

	str << std::setfill('0') << std::setw(4) << this->getYear() << "-"
		<< std::setfill('0') << std::setw(2) << this->getMonth() << "-"
		<< std::setfill('0') << std::setw(2) << this->getDay();
	return (str.str());
}

bool	Date::isLeapYear(int32_t year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/* GETTERS ****************************************************************** */

int32_t	Date::getYear(void) const {
	return (this->_year);
}

int32_t	Date::getMonth(void) const {
	return (this->_month);
}

int32_t	Date::getDay(void) const {
	return (this->_day);
}

/* EXCEPTIONS *************************************************************** */

const char*	Date::InvalidDateException::what(void) const throw() {
	return ("invalid date");
}

/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.toString();
	return (os);
}
