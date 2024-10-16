/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:40:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 09:15:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstdlib>
#include <algorithm>

#include "PmergeMe.hpp"

/* CONSTRUCTORS ************************************************************* */

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(void) {}

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {
	*this = other;
}

template <template <typename, typename> class T>
PmergeMe<T>::~PmergeMe(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

template <template <typename, typename> class T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe &other) {
	if (this == &other)
		return (*this);
	this->_c = other.c;
	return (*this);
}

template <template <typename, typename> class T>
const Element<T>	&PmergeMe<T>::operator[](int index) const {
	return (this->_c[index]);
}


/* ************************************************************************** */

template <template <typename, typename> class T>
void	PmergeMe<T>::_sort(const uint32_t size) {
	this->_pair();
	// this->_display("paired:\t");
	if (this->_c.size() > 1) {
		this->_sort(size << 1);
	}
	this->_insert(size << 1);
	// this->_display("insert:\t");
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_pair(void) {
	for (uint32_t i = 0; i + 1 < this->_c.size(); ++i) {
		this->_c[i].pair(this->_c[i + 1]);
		this->_c.erase(this->_c.begin() + i + 1);
	}
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_insert(const uint32_t size) {
	Element<T> element;

	this->_c[0].depair(element);
	this->_c.insert(this->_c.begin(), element);
	// this->_display("\t\tINITIAL: ");
	element.clear();
	for (uint32_t i = 0; i < this->_c.size(); ++i) {
		if (this->_c[i].size() != size) {
			continue;
		}
		this->_c[i].depair(element);
		// std::cout << "inserting: " << element.value();
		this->_c.insert(std::lower_bound(this->_c.begin(), this->_c.begin() + i, element), element);
		element.clear();
		// this->_display("\t\t THEN:   ");
	}
}

/* ************************************************************************** */

template <template <typename, typename> class T>
void	PmergeMe<T>::_display(const std::string &str) const {
	std::cout << str;
	for(uint32_t i = 0; i < this->_c.size(); ++i) {
		this->_c[i].display();
		std::cout << " ";
	}
	std::cout << (this->isSorted() ? "✅" : "❌") << std::endl;
}

/* ************************************************************************** */

template <template <typename, typename> class T>
bool	PmergeMe<T>::addArg(const char *str) {
	long	value;
	char	*endPtr;

	errno = 0;
	value = strtol(str, &endPtr, 10);
	if (errno || *endPtr != '\0' || value < 0 || value > UINT32_MAX) {
		return true;
	}

	this->_c.push_back(Element<T>(value));
	return false;
}

template <template <typename, typename> class T>
void	PmergeMe<T>::sort(void) {
	this->_display("Before:\t");
	this->_sort(1);
	this->_display("After:\t");
}

template <template <typename, typename> class T>
bool	PmergeMe<T>::isSorted(void) const {
	for (uint32_t i = 0; (i + 1) < this->_c.size(); ++i) {
		if ((*this)[i] > (*this)[i + 1]) {
			return (false);
		}
	}
	return (true);
}

/* GETTERS ****************************************************************** */

/* EXCEPTIONS *************************************************************** */
