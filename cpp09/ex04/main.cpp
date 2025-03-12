#include "PmergeMe.hpp"

int main() {
	// Example usage
	int arr[] = {5, 3, 1, 4, 2, 7, 16, 25, 6};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));

	PmergeMe sorter;
	sorter.sortVector(vec);
	sorter.sortDeque(deq);

	std::cout << "Sorted Vector: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Sorted Deque: ";
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << deq[i] << " ";
	std::cout << std::endl;

	return 0;
}
