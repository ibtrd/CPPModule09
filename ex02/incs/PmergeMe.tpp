/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:40:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/17 18:20:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <algorithm>

#include "PmergeMe.hpp"

template <template <typename, typename> class T>
 uint32_t	PmergeMe<T>::jacobsthals[66] = {3, 5, 11, 21, 43, 85, 171, 341,
 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

/* CONSTRUCTORS ************************************************************* */

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(void) {
	this->_start = std::clock();
}

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {
	*this = other;
}

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(const std::string &str) {
	this->_start = std::clock();
	this->_containerName = str;
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
	if (this->_c.size() > 1 && (*this)[1].size() == (size << 1)) {
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
	T<Element<T>, std::allocator<Element<T> > > sorted;
	Element<T>									element;

	// this->_display("\tSTART: ");
	this->_c.front().depair(element);
	// sorted.push_back(element);
	// sorted.push_back(this->_c.front());
	this->_c.insert(this->_c.begin(), element);
	// sorted.insert(this->_c.begin(), this->_c.front());

	element.clear();
	// uint32_t j = 1;
	// while (PmergeMe<T>::jacobsthals[j - 1] < this->_c.size()) {
	// 	uint32_t	end = PmergeMe<T>::jacobsthals[j - 1];
	// 	this->_display("\tJACOB: ");
		
	// 	for (uint32_t start = PmergeMe<T>::jacobsthals[j]; start != end; ++start) {
	// 		if (start >= this->_c.size()) {
	// 			continue;
	// 		}
	// 	}
	// }

	for (uint32_t i = 2; i < this->_c.size(); i += 2) {
			// std::cout << "inserting: " << this->_c[i].size() << "\t";
		if (this->_c[i].size() == size) {
			this->_c[i].depair(element);
			this->_c.insert(std::lower_bound(this->_c.begin(), this->_c.begin() + i, element), element);
			element.clear();
			// this->_display("\t\t THEN:   ");
		} else if (this->_c[i].size() >= (size >> 1)) {
			this->_c[i].depair(element, size >> 1);
			if (this->_c[i].size() == 0) {
				this->_c.pop_back();
			}
			this->_c.insert(std::lower_bound(this->_c.begin(), this->_c.begin() + i, element), element);
			element.clear();
			// this->_display("\t\t THEN:   ");
		}
	}
	// this->_c = sorted;
	// (void)size;
	// this->_display("END-> ");
}

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
	if (!*str || errno || *endPtr != '\0' || value < 0 || value > UINT32_MAX) {
		return true;
	}

	this->_c.push_back(Element<T>(value));
	return false;
}

template <template <typename, typename> class T>
void	PmergeMe<T>::sort(void) {
	this->_display("Before:\t");
	if (this->_c.size() > 1) {
		this->_sort(1);
	}
	double duration = (clock() - this->_start) / static_cast<double>(CLOCKS_PER_SEC);
	this->_display("After:\t");
	std::cout << "Time to process a range of " << this->_c.size()
		<< " elements with " << this->_containerName
		<< " : " << std::fixed << duration << "s" << std::endl;
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
