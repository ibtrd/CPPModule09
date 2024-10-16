/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:45:19 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 09:10:01 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Element.hpp"

/* CONSTRUCTORS ************************************************************* */

template <template <typename, typename> class T>
Element<T>::Element(void) {}

template <template <typename, typename> class T>
Element<T>::Element(const Element &other) {
	*this = other;
}

template <template <typename, typename> class T>
Element<T>::Element(const uint32_t value) {
	this->_e.push_back(value);
	this->_size = 1;
}

template <template <typename, typename> class T>
Element<T>::~Element(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

template <template <typename, typename> class T>
Element<T>	&Element<T>::operator=(const Element &other) {
	if (this == &other)
		return (*this);
	this->_e = other._e;
	this->_size = other._size;
	return (*this);
}

template <template <typename, typename> class T>
bool	Element<T>::operator<(const Element &other) const {
	return (this->_e[0] < other._e[0]);
}

template <template <typename, typename> class T>
bool	Element<T>::operator>(const Element &other) const {
	return (this->_e[0] > other._e[0]);
}

/* ************************************************************************** */

template <template <typename, typename> class T>
void	Element<T>::_sort(void) {
	if (this->_e[0] > this->_e[this->_size]) {
		return;
	}
	for (uint32_t i = 0; i < this->_size; ++i) {
		const uint32_t swap = this->_e[i];
		this->_e[i] = this->_e[i + this->_size];
		this->_e[i + this->_size] = swap;
	}
}

/* ************************************************************************** */

template <template <typename, typename> class T>
void	Element<T>::push(uint32_t n) {
	this->_e.push_back(n);
	this->_size = 1;
}

template <template <typename, typename> class T>
void	Element<T>::pair(const Element &other) {
	for (uint32_t i = 0; i < other._e.size(); ++i) {
		this->_e.push_back(other._e[i]);
	}
	this->_sort();
	this->_size <<= 1;
}

template <template <typename, typename> class T>
void	Element<T>::depair(Element &other) {
	this->_size >>= 1;
	other._size = this->_size;
	for (uint32_t i = 0; i < this->_size; ++i) {
		other._e.push_back(this->_e[this->_size]);
		this->_e.erase(this->_e.begin() + this->_size);
	}
}


template <template <typename, typename> class T>
void	Element<T>::display(void) const {
	if (this->_e.size() == 1) {
		std::cout << this->_e[0];
	} else {
		std::cout << "[ ";
		for (uint32_t i = 0; i < this->_e.size(); ++i) {
			std::cout << this->_e[i] << " ";
		}
		std::cout << "]";
	}
}

template <template <typename, typename> class T>
void	Element<T>::clear(void) {
	this->_e.clear();
	this->_size = 0;
}


/* GETTERS ****************************************************************** */

template <template <typename, typename> class T>
uint32_t	Element<T>::size(void) const {
	return (this->_size);
}

template <template <typename, typename> class T>
uint32_t	Element<T>::value(void) const {
	return (this->_e[0]);
}

/* EXCEPTIONS *************************************************************** */
