/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/20 05:18:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ..." << std::endl;
		return (1);
	}
	{
		PmergeMe<std::vector>	test("std::vector");
		for (int i = 1; i < ac; ++i) {
			if (test.addArg(av[i])) {
				std::cout << "Error: " << av[i] << ": invalid argument" << std::endl;
				return 1;
			}
		}
		test.sort();
	}
	std::cout << std::endl;
	{
		PmergeMe<std::deque>	test("std::deque");
		for (int i = 1; i < ac; ++i) {
			if (test.addArg(av[i])) {
				std::cout << "Error: " << av[i] << ": invalid argument" << std::endl;
				return 1;
			}
		}
		test.sort();
	}
	return 0;
}
