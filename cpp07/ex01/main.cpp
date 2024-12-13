#include "iter.hpp"

using std::string;

/*
	This function is used to print the elements of the array.
*/
int main() {
   int arr[] = {5, 3, -4, 1, 546, 89};
   ::iter(arr, 6, &print);

   string str[4]= {"hi", "hola", "hallo", "hey"};
   ::iter(str, 4, &print);
}
