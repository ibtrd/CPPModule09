/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:04:51 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/11 04:09:00 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <stdint.h>
#include <ostream>

class Date
{
	private:
		int32_t _year;
		int32_t _month;
		int32_t _day;

	public:
		Date(void);
		Date(const Date &);
		Date(int32_t, int32_t, int32_t);

		~Date(void);

		Date	&operator=(const Date &);

		bool	isValidDate(void) const;

		static bool	isLeapYear(int32_t);

		int32_t	getYear(void) const;
		int32_t	getMonth(void) const;
		int32_t	getDay(void) const;

		class InvalidDate : public std::exception {
			const char* what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &, const Date &date);

#endif /* ******************************************************************* */
