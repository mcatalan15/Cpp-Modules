#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		// Public method to sort using vector
		void sortVector(std::vector<int>& arr);
		void sortDeque(std::deque<int>& arr);

		// Binary insertion helper function
		void binaryInsert(std::vector<int>& arr, int element);
		void binaryInsert(std::deque<int>& arr, int element);

		// Recursive Ford-Johnson
		void fordJohnsonSortVector(std::vector<int>& arr);
		void fordJohnsonSortDeque(std::deque<int>& arr);
};
