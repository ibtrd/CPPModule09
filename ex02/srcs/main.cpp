/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 04:56:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

#include "PmergeMe2.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ..." << std::endl;
		return (1);
	}
	{
		PmergeMe<std::vector>	test;
		// for (int i = 1; i < ac; ++i) {
		// 	if (test.addArg(av[i])) {
		// 		std::cout << "Error: " << av[i] << ": invalid argument" << std::endl;
		// 		return 1;
		// 	}
		// }
		// test.displayContent();
		// test.sort();
		// test.displayContent();
		// if (false == test.isSorted()) {
		// 	std::cout << "Container is not sorted!" << std::endl;
		// }
	}
	// std::cout << std::endl;
	// {
	// 	PmergeMe<std::deque<uint32_t> >	test;
	// 	for (int i = 1; i < ac; ++i) {
	// 		if (test.addArg(av[i])) {
	// 			std::cout << "Error: " << av[i] << ": invalid argument" << std::endl;
	// 			return 1;
	// 		}
	// 	}
	// 	test.sort();
	// }
	return 0;
}
