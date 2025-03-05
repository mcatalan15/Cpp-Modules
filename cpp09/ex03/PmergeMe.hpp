#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <stdexcept>
#include <vector>
#include <sys/time.h>
#include <ctime>

using std::string;

class PmergeMe {
	private:
		std::vector<unsigned int>	vec;
		//std::deque<unsigned int>	deq;
		string						str;

		//functions
		void	insertionSort(std::vector<unsigned int>& arr, int left, int right);
		void	merge(std::vector<unsigned int>& arr, int left, int mid, int right);
		void	mergeInsertSortHelper(std::vector<unsigned int>& arr, int left, int right);
		
	public:
		PmergeMe (char **argv);
		PmergeMe (const PmergeMe &cpy);
		~PmergeMe ();
		PmergeMe &operator=(const PmergeMe &src);
		
		//Functions
		void	mergeInsertSort();
		void	printVect() const;
		//Exceptions
		class errorException : public std::logic_error {
			public:
				errorException();
		};
};

#endif