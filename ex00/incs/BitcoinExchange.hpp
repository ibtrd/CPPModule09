/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/22 13:31:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>

# include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float>	_prices;

		void	_parseDatabase(const std::string &path);
		void	_evaluateQuery(const std::string &str) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange(const std::string &path);

		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &other);

		int8_t	parseQueryFile(const std::string &path) const;

		class InvalidDatabaseException : public std::exception {
			const char* what(void) const throw();
		};
};

#endif /* ******************************************************************* */
