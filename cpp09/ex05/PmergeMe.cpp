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

		// Jacobsthal numbers up to n=12 (sufficient for 3000 elements)
		static const int _jacobsthal[13];

		// Helper functions
		void mergeInsertionSortV(std::vector<int>& arr);
		void insertUsingJacobsthalV(std::vector<int>& sorted, const std::vector<int>& smaller);
		int binarySearchInsertPositionV(const std::vector<int>& arr, int value);

	public:
		// Orthodox Canonical Form
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// Public interface
		void	sortV();
		void	printV() const;
		void	printT(int amount);

		class errorException : public std::logic_error {
			public:
				errorException();
		};
};

// Jacobsthal numbers up to n=12
const int PmergeMe::_jacobsthal[13] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};

// Default constructor
PmergeMe::PmergeMe(char **argv) {
	for (int i = 1; argv[i]; i++) {
		int num = atoi(argv[i]);
		if (num < 0) {
			throw errorException();
		}
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Binary search to find the insertion position
int PmergeMe::binarySearchInsertPositionV(const std::vector<int>& arr, int value) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Insert smaller elements using Jacobsthal numbers
void PmergeMe::insertUsingJacobsthalV(std::vector<int>& sorted, const std::vector<int>& smaller) {
    size_t j = 0;
    size_t k = 0;
    while (j < smaller.size()) {
        size_t next = _jacobsthal[k];
        if (next >= smaller.size()) {
            next = smaller.size();
        }
        for (size_t i = next; i > j; --i) {
            int pos = binarySearchInsertPositionV(sorted, smaller[i - 1]);
            sorted.insert(sorted.begin() + pos, smaller[i - 1]);
        }
        j = next;
        ++k;
    }
}

// Merge-insertion sort (Ford-Johnson algorithm)
void PmergeMe::mergeInsertionSortV(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Step 1: Pair and sort
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] < arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }

    // Step 2: Extract larger elements and recursively sort
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largerElements.push_back(pairs[i].second);
    }
    if (arr.size() % 2 != 0) {
        largerElements.push_back(arr.back()); // Add the unpaired element
    }

    mergeInsertionSortV(largerElements);

    // Step 3: Insert smaller elements using Jacobsthal numbers
    std::vector<int> smallerElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smallerElements.push_back(pairs[i].first);
    }
    insertUsingJacobsthalV(largerElements, smallerElements);

    // Update the array
    arr = largerElements;
}

// Public sort function
void PmergeMe::sortV() {
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	mergeInsertionSortV(_vec);
	gettimeofday(&end, NULL);
	this->_vecT = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;
}

/*void PmergeMe::sortD() {
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	mergeInsertionSortD(_vec);
	gettimeofday(&end, NULL);
	this->_deqT = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;
}*/

// Print the sorted data
void PmergeMe::printV() const {
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

// Error exception constructor
PmergeMe::errorException::errorException() : std::logic_error("Error: Invalid input") {}

void	PmergeMe::printT(int amount) {
	if (this->_deqT >= 1000 && this->_vecT >= 1000) {
		this->_vecT /= 1000;
		//this->_deqT /= 1000;
	}
	std::cout << "Time to process a range of " << amount << " elements with std::vector : " << std::fixed << std::setprecision(5) << this->_vecT << " us" << std::endl;
}

int main(int argc, char **argv) {
		if (argc < 2) {
			std::cout << "Usage: " << argv[0] << " <numbers>" << std::endl;
			return 1;
		} else if (argc > 3001) {
			std::cout << "Error: N numbers must be less than 3000." << std::endl;
			return 1;
		}
		try {
			// Vector
			PmergeMe sorter(argv);
			std::cout << "Before sorting: ";
			sorter.printV();
			
			sorter.sortV();
			
			std::cout << "After sorting: ";
			sorter.printV();
			sorter.printT(argc - 1);
			
		} catch (PmergeMe::errorException &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		return 0;
}