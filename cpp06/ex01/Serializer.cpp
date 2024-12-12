#include "Serializer.hpp"

//Constructor
Serializer::Serializer() {}

// Copy constructor
Serializer::Serializer(const Serializer &src) { *this = src; }

//Destructor
Serializer::~Serializer() {}

//Operator overload
Serializer &Serializer::operator=(const Serializer &src) { (void)src; return (*this); }

/*
	Serialize function trasnform an in-memory object into a format for storage or transfer in this
	case a pointer.

	What is reinterpret_cast? Is a type of casting that reinterpret the bits in an object
	or pointer without modifying the representation.
*/
uintptr_t Serializer::serialize(Data *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

/*
	Deserialize function reconstruct the original object from serialized function.
*/
Data* Serializer::deserialize(uintptr_t raw) { return(reinterpret_cast<Data *>(raw)); }
 
