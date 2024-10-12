#include "PmergeMe.hpp"

/* CONSTRUCTORS ************************************************************* */

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	if (this == &other)
		return (*this);
	// Copy instructions
	return (*this);
}

/* ************************************************************************** */

/* GETTERS ****************************************************************** */

/* EXCEPTIONS *************************************************************** */
