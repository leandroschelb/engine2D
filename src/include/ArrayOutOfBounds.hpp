#ifndef ARRAY_OUT_OF_BOUNDS_H
#define ARRAY_OUT_OF_BOUNDS_H
#include <iostream>
class ArrayOutOfBounds : public std::exception{
	public:
		ArrayOutOfBounds(int);
		virtual const char* what() const throw();
		int getArray();
	private:
		int array;
};

#endif