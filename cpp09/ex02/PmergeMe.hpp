#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#define MICROSEC 1000000

using std::string;

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int>	_deq;
		float			_vecT;
		float			_deqT;

		// Jacobsthal numbers up to n=13 (sufficient for 3000 elements)
		static const int _jacobsthal[13];

		// Helper functions
		void mergeInsertionSortV(std::vector<int>& arr);
		void insertUsingJacobsthalV(std::vector<int>& sorted, const std::vector<int>& smaller);
		int binarySearchInsertPositionV(const std::vector<int>& arr, int value);

		void mergeInsertionSortD(std::deque<int>& arr);
		void insertUsingJacobsthalD(std::deque<int>& sorted, const std::deque<int>& smaller);
		int binarySearchInsertPositionD(const std::deque<int>& arr, int value);
	public:
		// Orthodox Canonical Form
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// Public interface
		void	sortV();
		void	printV() const;
		void	printT(int amount, bool flag);
		void	sortD();
		void	printD() const;
		class errorException : public std::logic_error {
			public:
				errorException();
		};
};
