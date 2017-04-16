//
// Created by alex on 16.04.17.
//

#ifndef VECTOR_VECTOR_HPP
#define VECTOR_VECTOR_HPP


#include <iostream>

template <typename T> class Vector
{
private:
	T *array;
	int arraySize;

	Vector(int size) {
		arraySize = size;
		array = new T[size];
	}

public:
	Vector() {
		this->arraySize = 0;
		this->array = nullptr;
	}

	Vector(Vector& rhs) : arraySize(rhs.arraySize) {
		this->array = new T[arraySize];
		for(int i = 0; i < arraySize; i++)
			this->array[i] = rhs.array[i];
	}

	Vector& operator= (const Vector& s)
	{
		if (this == &s)
			return *this;

		arraySize = s.arraySize;

		delete[] array;
		array = new T[arraySize];

		for(int i = 0; i < arraySize; i++)
			this->array[i] = s.array[i];

		return *this;
	}

	Vector operator + (const Vector& s) const {
		Vector new_vector(arraySize + s.arraySize);

		for(int i = 0; i < arraySize; i++)
			new_vector.array[i] = array[i];

		for(int i = arraySize, j = 0; i < (s.arraySize + arraySize) ; i++, j++)
			new_vector.array[i] = s.array[j];

		return new_vector;
	}

	void push_back(T data) {
		T *result = new T[++this->arraySize];

		for(int index = 0; index < this->arraySize; index++) {
			if(index != this->arraySize-1) {
				result[index] = this->array[index];
			} else {
				result[index] = data;
				break;
			}
		}

		delete[] this->array;
		this->array = result;
	}

	T pop_back() {
			return this->popIndex(this->arraySize-1);
		}

	void clear() {
		if(this->array != nullptr) {
			this->arraySize = 0;
			delete[] this->array;

			this->array = nullptr;
		}
	}


	T& operator [](const int index) {
		if (index < this->arraySize)
			return this->array[index];
		else
			return this->array[arraySize-1];
	}

	const T operator [] (const int index) const {
		if (index < this->arraySize)
			return this->array[index];
		else
			return this->array[arraySize-1];
	}

	int size() const {
			return this->arraySize;
	}

	void pushIndex(T data, int index) {
		int oldSize = this->arraySize;

		this->arraySize = (this->arraySize >= index) ? (++this->arraySize) :
						  (this->arraySize + (index - this->arraySize) + 1);

		T *result = new T[this->arraySize];

		int arrIndex = 0;

		for(int index2 = 0; index2 < this->arraySize; index2++) {
			if(index2 == index) {
				result[index2] = data;
				continue;
			}

			if(arrIndex != oldSize) {
				result[index2] = this->array[arrIndex++];
			}
		}

		delete[] this->array;
		this->array = result;
	}

	T popIndex(int index) {
		if(index >= this->arraySize)
		return 0;

		T *result = new T[--this->arraySize];

		T resItem;
		int resIndex = 0;

		for(int index2 = 0; index2 < this->arraySize+1; index2++) {
			T item = this->array[index2];

			if(index == index2) {
				resItem = item;
				continue;
			}
			result[resIndex++] = this->array[index2];
		}

		delete[] this->array;
		this->array = result;
			return resItem;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		for (int i = 0; i < v.arraySize; i++)
		os << v.array[i] << "; ";

		return os;
	}

	~Vector() {
		delete[] array;
	}

};


#endif //VECTOR_VECTOR_HPP
