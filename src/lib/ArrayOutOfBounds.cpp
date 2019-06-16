#include "ArrayOutOfBounds.hpp"

ArrayOutOfBounds::ArrayOutOfBounds(int a) : array(a) {}

const char* ArrayOutOfBounds::what() const throw()
{
	return "ERRO: Array out of bounds.";
}

int ArrayOutOfBounds::getArray()
{
	return this->array;
}