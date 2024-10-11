/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:16:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/11 04:16:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	this->isValidDate();
}

Date::~Date(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Date	&Date::operator=(const Date &other)
{
	if (this == &other)
		return (*this);
	this->_year = other._year;
	this->_month = other._month;
	this->_day = other._month;
	return (*this);
}

/* ************************************************************************** */

bool	Date::isValidDate(void) const {
	const int32_t daysInMonth[] = { 31, 28 + Date::isLeapYear(this->_year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (this->_year < 0
		|| this->_month < 1 || this->_month > 12
		|| this->_day < 0 || this->_day > daysInMonth[this->_month - 1]) {
			throw Date::InvalidDate();
	}
	return (true);
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

const char*	Date::InvalidDate::what(void) const throw() {
	return ("Invalid date");
}

/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return (os);
}
