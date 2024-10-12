/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:04:51 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/12 15:55:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <stdint.h>

class Date
{
	private:
		int32_t _year;
		int32_t _month;
		int32_t _day;

	public:
		Date(void);
		Date(const Date &other);
		Date(int32_t year, int32_t month, int32_t day);
		Date(const std::string &string);

		~Date(void);

		Date	&operator=(const Date &other);
		Date	&operator++(void);
		Date	operator++(int);

		bool	operator==(const Date &other) const;
		bool	operator!=(const Date &other) const;
		bool	operator<(const Date &other) const;

		bool		isValidDate(void) const;
		std::string	toString(void) const;

		static bool	isLeapYear(int32_t year);

		int32_t	getYear(void) const;
		int32_t	getMonth(void) const;
		int32_t	getDay(void) const;

		class InvalidDateException : public std::exception {
			const char* what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Date &date);

#endif /* ******************************************************************* */
