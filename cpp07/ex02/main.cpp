#include "Array.hpp" 
#include "Array.tpp" 

template <class T>
void	printArray(Array<T> arr){
	try{
		for(unsigned int i=0; i < arr.size(); i++){
			std::cout << arr[i] << std:: endl;
		}
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}
}

void	fillArrayInt(){

	unsigned int	ARRAY_SIZE = 6;
	Array<int> arr(ARRAY_SIZE);

	std::cout << std::endl << CYAN << "----- Fill the array with ints ----- " << RESET << std::endl;
	try{
		for(unsigned int i=0; i < arr.size(); i++){
			arr[i] = i;
		}
		std::cout << "Array is filled successfully!" << std:: endl;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Try to fill array out of range ----- " << RESET << std::endl;
	try{
		arr[ARRAY_SIZE] = 42;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}
	std::cout << std::endl << CYAN << "----- Print array ----- " << RESET << std::endl;
	printArray(arr);
}

void	fillArrayString() {

	unsigned int	ARRAY_SIZE = 6;
	Array<std::string> arr(ARRAY_SIZE);

	std::cout << std::endl << CYAN << "----- Fill the array with strings ----- " << RESET << std::endl;
	try {
		for(unsigned int i=0; i < arr.size(); i++){
			arr[i] = "hello" + std::to_string(i);
        }
		std::cout << "Array is filled successfully!" << std:: endl;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Try to fill array out of range ----- " << RESET << std::endl;
	try{
		arr[ARRAY_SIZE] = "byebye";
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Print array ----- " << RESET << std::endl;
	printArray(arr);
}

void	testDeepCopyArray(){
	
	int	ARRAY_SIZE = 4;
	Array<int> arr(ARRAY_SIZE);

	std::cout << std::endl << CYAN << "----- Fill the array ----- " << RESET << std::endl;
	
	try{
		for(unsigned int i=0; i < arr.size(); i++){
			arr[i] = i;
		}
		std::cout << "Array is filled successfully!" << std:: endl;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Test operator = constructor ----- " << RESET << std::endl;
	Array<int> arrCopy = arr;

	std::cout << std::endl << CYAN << "----- Print original array ----- " << RESET << std::endl;
	printArray(arr);

	std::cout << std::endl << CYAN << "----- Print copied array ----- " << RESET << std::endl;
	printArray(arrCopy);

	std::cout << std::endl << "-> Modify first element." << std::endl;
	try{
		arrCopy[0] = 42;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Print original array ----- " << RESET << std::endl;
	printArray(arr);

	std::cout << std::endl << CYAN << "----- Print copied array ----- " << RESET << std::endl;
	printArray(arrCopy);	

	std::cout << std::endl << "-> Copy array = original array" << std::endl;
	arrCopy = arr;
	std::cout << std::endl << CYAN << "----- Print copied array ----- " << RESET << std::endl;
	printArray(arrCopy);

}

void	testConstructors(){
	
	int	ARRAY_SIZE = 4;
	Array<int> arr(ARRAY_SIZE);

	std::cout << std::endl << CYAN << "----- Fill the array ----- " << RESET << std::endl;
	
	try{
		for(unsigned int i=0; i < arr.size(); i++){
			arr[i] = i;
		}
		std::cout << "Array is filled successfully!" << std:: endl;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Test copy constructor ----- " << RESET << std::endl;
	Array<int> arrCopy(arr);

	std::cout << std::endl << CYAN << "----- Print original array ----- " << RESET << std::endl;
	printArray(arr);

	std::cout << std::endl << CYAN << "----- Print copied array ----- " << RESET << std::endl;
	printArray(arrCopy);

	std::cout << std::endl << "-> Modify first element." << std::endl;
	try{
		arrCopy[0] = 42;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

	std::cout << std::endl << CYAN << "----- Print original array ----- " << RESET << std::endl;
	printArray(arr);

	std::cout << std::endl << CYAN << "----- Print copied array ----- " << RESET << std::endl;
	printArray(arrCopy);	

	std::cout << std::endl << CYAN << "----- Test empty constructor ----- " << RESET << std::endl;
	Array<std::string> arr1;
	try{
			arr1[0] = 42;
	} catch(std::exception e){
		std::cout << RED << "Index is out of range" << RESET << std:: endl;
	}

}

int main() {

	fillArrayInt();
	fillArrayString();

	testDeepCopyArray();
	testConstructors();

	return (0);
}

