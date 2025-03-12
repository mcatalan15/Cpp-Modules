#include "PmergeMe.hpp"

// Orthodox Canonical Form
// Constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

// Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

// Sort using vector
void PmergeMe::sortVector(std::vector<int>& arr) {
	_vec = arr;
	fordJohnsonSortVector(_vec);
	arr = _vec;
}

// Sort using deque
void PmergeMe::sortDeque(std::deque<int>& arr) {
	_deq = arr;
	fordJohnsonSortDeque(_deq);
	arr = _deq;
}

/*
	Binary Insertion Sort
	This algorithm checks from the middle length of the array.
	Checks if an element is greater than the middle element.
	This way, the element is inserted into the correct position.
*/
void PmergeMe::binaryInsert(std::vector<int>& arr, int element) {
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < element) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	arr.insert(arr.begin() + low, element);
}

// Deque binaryInsert function
void PmergeMe::binaryInsert(std::deque<int>& arr, int element) {
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < element)
			low = mid + 1;
		else
			high = mid - 1;
	}
	arr.insert(arr.begin() + low, element);
}

/*
	Recursive Ford-Johnson sort for vector
	Step 1:
		Divide the array into pairs and sort them.
		Each pair is sorted. This way the smaller elements are placed in the first position.
	
	Step 2:
		Recursive Ford-Johnson sort for deque and vector
		We extract the largest element from the pairs into the new largerElements array.
		Then we recursively use Ford-Johnson algorithm with the largerElements array.
		This way, we ensure that the larger elements are sorted efficiently 
		using binary insertion.
	
	Step 3:
		Then we insert the smaller elements into the sorted largerElements array using the binaryInsert function.
		After we insert the smaller elements, we check if the largerElements has an impar number of elements.
		If it does, we insert the last element into the sorted largerElements array using the binaryInsert function.
*/
void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
	if (arr.size() <= 1) return;

	// Step 1: Pairing and Sorting
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size() - 1; i += 2) {
		if (arr[i] < arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Recursive Sorting of Larger Elements
	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		largerElements.push_back(pairs[i].second);
	fordJohnsonSortVector(largerElements);

	// Step 3: Insert Smaller Elements Using Ford-Johnson Sequence
	std::vector<int> sortedList = largerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		binaryInsert(sortedList, pairs[i].first);

	// Handle the last element if the list has an odd length
	if (arr.size() % 2 != 0)
		binaryInsert(sortedList, arr.back());

	arr = sortedList;
}

// Recursive Ford-Johnson sort for deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
	if (arr.size() <= 1) return;

	// Step 1: Pairing and Sorting
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size() - 1; i += 2) {
		if (arr[i] < arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Recursive Sorting of Larger Elements
	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		largerElements.push_back(pairs[i].second);
	fordJohnsonSortDeque(largerElements);

	// Step 3: Insert Smaller Elements Using Ford-Johnson Sequence
	std::deque<int> sortedList = largerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		binaryInsert(sortedList, pairs[i].first);

	// Handle the last element if the list has an odd length
	if (arr.size() % 2 != 0)
		binaryInsert(sortedList, arr.back());

	arr = sortedList;
}
