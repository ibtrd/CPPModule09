/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:18:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/13 00:28:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);

	~PmergeMe(void);

	PmergeMe	&operator=(const PmergeMe &other);
};

#endif /* ******************************************************************* */
