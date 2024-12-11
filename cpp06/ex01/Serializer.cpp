#include "Serializer.hpp"

//Constructor
Serializer::Serializer() {}

// Copy constructor
Serializer::Serializer(const Serializer &src) { *this = src; }

//Destructor
Serializer::~Serializer() {}

//Operator overload
Serializer &Serializer::operator=(const Serializer &src) { (void)src; return (*this); }

//Functions
uintptr_t Serializer::serialize(Data *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

// Deserialize function
Data* Serializer::deserialize(uintptr_t raw) { return(reinterpret_cast<Data *>(raw)); }
 
