/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:58:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 21:02:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_prices;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);

		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &);
};

#endif /* ******************************************************************* */
