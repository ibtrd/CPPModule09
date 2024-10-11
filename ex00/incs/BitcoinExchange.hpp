/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/11 03:34:00 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <utility>
# include <string>

#include <Date.hpp>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_prices;

		void	_parseDatabase(void);
		void	_addEntry(std::string &);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);

		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &);
};

#endif /* ******************************************************************* */
