#include "PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe(char **argv) {
	for (int i = 1; argv[i]; ++i) {
		int num = std::atoi(argv[i]);
		if (num < 0) {
			throw errorException();
		}
		vec.push_back(static_cast<unsigned int>(num));
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &cpy) : vec(cpy.vec), str(cpy.str) {}

// Destructor
PmergeMe::~PmergeMe() {}

// Assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		vec = src.vec;
		str = src.str;
	}
	return *this;
}

// Order with Merge-Insert Sort
void PmergeMe::mergeInsertSort() { mergeInsertSortHelper(vec, 0, vec.size() - 1); }

// Funcion auxiliar para Merge-Insert Sort
void	PmergeMe::mergeInsertSortHelper(std::vector<unsigned int>& arr, int left, int right) {
	// Si el tamanyo del subarreglo es pequeno, usa Insertion Sort
	if (right - left <= 16) {
		insertionSort(arr, left, right);
		return ;
	}
	// Divide el arreglo en dos mitades
	int mid = left + (right - left) / 2;
	
	// Ordena recursivamente la primera mitad
	mergeInsertSortHelper(arr, left, mid);
	
	// Ordena recursivamente la segunda mitad
	mergeInsertSortHelper(arr, mid + 1, right);
	
	// Combina las dos mitades ordenadas
	merge(arr, left, mid, right);
}

// Funcion para Insertion Sort
void PmergeMe::insertionSort(std::vector<unsigned int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		unsigned int key = arr[i];
		int j = i - 1;
		while (j >=left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Funcion para combinar dos mitades ordenadas
void	PmergeMe::merge(std::vector<unsigned int>& arr, int left, int mid, int right) {
	std::vector<unsigned int> tmp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	// Combina las dos mitades ordenadas
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	// Copia los argumentos restantes de la primera mitad (si hay)
	while (i <= mid)
		tmp[k++] = arr[i++];
	// Copia los elementos restantes de la segunda mitad (si hay)
	while (j <= right)
		tmp[k++] = arr[j++];
	// Copia los elementos ordenados al arreglo original
	for(int p = 0; p < k; ++p)
		arr[left + p] = tmp[p];
}

void	PmergeMe::printVect() const {
	for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
}

PmergeMe::errorException::errorException() : std::logic_error("Error: Invalid input.") {}
