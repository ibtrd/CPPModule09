/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:02:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 04:22:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	DEBUGprintS(const std::vector<uint32_t> &sorted) {
	std::cerr << "SORTED=> ";
	for (std::vector<uint32_t>::size_type i = 0; i < sorted.size(); ++i) {
		std::cerr << sorted[i] << " ";
	}
	std::cerr << std::endl;
}

#include <cerrno>
#include <cstdlib>
#include <algorithm>

#include "PmergeMe.hpp"

/* CONSTRUCTORS ************************************************************* */

template <typename T>
PmergeMe<T>::PmergeMe(void) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &other) {
	*this = other;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

template <typename T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe<T> &other) {
	if (this == &other)
		return (*this);
	this->_c = other._c;
	return (*this);
}

/* ************************************************************************** */

template <typename T>
bool	PmergeMe<T>::addArg(const char *str) {
	long	value;
	char	*endPtr;

	errno = 0;
	value = strtol(str, &endPtr, 10);
	if (errno || *endPtr != '\0' || value < 0 || value > UINT32_MAX) {
		return true;
	}
	this->_c.push_back(static_cast<uint32_t>(value));
	return false;
}

template <typename T>
void	PmergeMe<T>::sort(void) {
	this->_sort(1);
}

template <typename T>
void	PmergeMe<T>::displayContent(void) const {
	typename T::const_iterator it = this->_c.begin();

	while (it != this->_c.end()) {
		std::cout << *it;
		if (++it != this->_c.end()) {
			std::cout << " ";
		} else {
			std::cout << std::endl;
		}
	}
}

template <typename T>
void	PmergeMe<T>::displayContent(const uint32_t pairSize) const {
	typename T::const_iterator it = this->_c.begin();

	uint32_t i = 0;
	std::cout << "\n";
	while (it != this->_c.end()) {
		std::cout << *it;
		if (++it != this->_c.end()) {
			if (++i == (pairSize << 1)) {
				std::cout << "  |  ";
				i = 0;
			} else {
				std::cout << " ";
			}
		} else {
			std::cout << std::endl;
		}
	}
	std::cout << "\n";
}

template <typename T>
bool	PmergeMe<T>::isSorted(void) const {
	for (typename T::const_iterator it = this->_c.begin(); it != this->_c.end() && (it + 1) != this->_c.end(); ++it) {
		if (*it > *(it + 1)) {
			return (false);
		}
	}
	return (true);
}

/* ************************************************************************** */

template <typename T>
void	PmergeMe<T>::_sort(const uint32_t pairSize) {
	const uint32_t pairs = this->_c.size() / (pairSize << 1);

	// std::cerr << "_sort(pairSize = " << pairSize << ")\n";
	this->_sortPairs(pairs, pairSize);
	// this->displayContent(pairSize);
	if (pairs > 1) {
		this->_sort(pairSize << 1);
	}
	// std::cerr << "_inserting()\n";
	this->_insert(pairs, pairSize);
	
	// std::cerr << "_inserting() DONE\n";
	// this->displayContent(pairSize);
}

template <typename T>
void	PmergeMe<T>::_sortPairs(const uint32_t pairs, const uint32_t pairSize) {

	for (uint32_t i = 0; i < pairs; ++i) {
		const uint32_t index = i * (pairSize << 1);
		if (this->_c[index] < this->_c[index + pairSize]) {
			this->_swapPairs(index, pairSize);
		}
	}
}

template <typename T>
void	PmergeMe<T>::_swapPairs(const uint32_t index, const uint32_t pairSize) {
	for (uint32_t i = 0; i < pairSize; ++i) {
		std::swap(this->_c[index + i], this->_c[index + pairSize + i]);
	}
}

template <typename T>
void	PmergeMe<T>::_insert(const uint32_t pairs, const uint32_t pairSize) {
	T	sorted;

	this->displayContent(pairSize);
	this->_pushLeft(pairs, pairSize, sorted);
	std::cerr << "pusing LEFTS, this->_c.size() = " << this->_c.size() << " | " << sorted.size() << " = sorted.size() | ";
	DEBUGprintS(sorted);
	this->_insertRight(pairs, pairSize, sorted);
	std::cerr << "Inserting RIGHTS, this->_c.size() = " << this->_c.size() << " | " << sorted.size() << " = sorted.size() | ";
	DEBUGprintS(sorted);
	this->_insertLeftovers(pairs, pairSize, sorted);
	std::cerr << "LEFTOVERS, this->_c.size() = " << this->_c.size() << " | " << sorted.size() << " = sorted.size() | ";
	DEBUGprintS(sorted);
	this->_c = sorted;
	std::cerr << "END!!\n\n";
}

template <typename T>
void	PmergeMe<T>::_pushLeft(const uint32_t pairs, const uint32_t pairSize, T &sorted) {
	for (uint32_t p = 0; p < pairs; ++p) {
		for (uint32_t i = 0; i < pairSize; ++i) {
			sorted.push_back(this->_c[p * (pairSize << 1) + i]);
		}
	}
}

template <typename T>
void	PmergeMe<T>::_insertRight(const uint32_t pairs, const uint32_t pairSize, T &sorted) {
	sorted.insert(sorted.begin(), this->_c.begin() + pairSize, this->_c.begin() + (pairSize << 1));
	for (uint32_t p = 1; p < pairs; ++p) {
		const uint32_t pos = _getInsertIndex(p, pairSize, sorted, this->_c[p * (pairSize << 1) + pairSize]);
		sorted.insert(sorted.begin() + (pos * pairSize), this->_c.begin() + ((p * (pairSize << 1)) + pairSize), this->_c.begin() + ((p + 1) *pairSize << 1));
	}
}

template <typename T>
void	PmergeMe<T>::_insertLeftovers(const uint32_t pairs, const uint32_t pairSize, T &sorted) {
	uint32_t leftovers = this->_c.size() % (pairSize << 1);
	uint32_t offset = 0;

	while (leftovers / pairSize) {
		const uint32_t pos = _getInsertIndex(pairs, pairSize, sorted, this->_c[pairs * (pairSize << 1)]);
		std::cerr << "pos index =" << pos << std::endl;
		sorted.insert(sorted.begin() + (pos * pairSize), this->_c.begin() + (pairs * (pairSize << 1) + offset * pairSize), this->_c.begin() + ((pairs + offset) * (pairSize << 1)) + pairSize);
		leftovers -= pairSize;
		offset++;
		// std::cerr << "REST >>>>" << leftovers << "<<<<< insert at->" << pos << std::endl;
	}
	sorted.insert(sorted.end(), this->_c.begin() + (pairs * (pairSize << 1)) + (offset * pairSize) , this->_c.end());
}

template <typename T>
uint32_t	PmergeMe<T>::_getInsertIndex(int32_t max, const uint32_t pairSize, const T &sorted, const uint32_t toInsert) {
	int32_t min = 0;
	max *= 2;
	std::cerr << "interting " << toInsert << " between 0 and " << max << "  ";
	std::cerr << "sorted.size() = " << sorted.size() << "  ";
	DEBUGprintS(sorted);
	
	while (min <= max && (max * pairSize) < static_cast<uint32_t>(sorted.size())) {
		int32_t mid = min + (max - min) / 2;
		std::cerr << "sorted.size()=" << sorted.size() << " min= " << min * pairSize << " mid = " << mid * pairSize << " max = " << max * pairSize << " sorted[mid]= " << sorted[mid * pairSize] << "\n";
		if (toInsert == sorted[mid * pairSize]) {
			return (mid);
		}
		if (toInsert > sorted[mid * pairSize]) {
			min = mid + 1;
		} else {
			max = mid - 1;
		}
	}
	return (min);
}



/* GETTERS ****************************************************************** */

template <typename T>
const T	&PmergeMe<T>::getContainer(void) const {
	return (this->_c);
}

/* EXCEPTIONS *************************************************************** */
