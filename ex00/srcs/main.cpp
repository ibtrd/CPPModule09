/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/20 23:56:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error: no argument provided" << std::endl;
		return (1);
	}

	BitcoinExchange	btc;

	try {
		btc = BitcoinExchange("./data.csv");
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (btc.parseQueryFile(av[1]) != 0);
}
