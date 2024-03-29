#pragma once
#include <iostream>

template <typename T>
class MyVector
{
public:
	MyVector(size_t capacity) : v_capacity(capacity)
	{
		v_values = new T[v_capacity];
	}
	MyVector() {};

	~MyVector()
	{
		delete[] v_values;
	}

	MyVector(const MyVector&) = delete; // запрещаем конструктор копирования
	MyVector& operator=(const MyVector&) = delete; // запрещаем оператор присваивания

	void push_back(T value)
	{
		if (v_size == v_capacity)
		{

			v_capacity = v_capacity > 0 ? v_capacity * 2 : 1;
			T* newArr = new T[v_capacity];
			copy(v_values, newArr, v_size);
			delete[] v_values;
			v_values = newArr;
		}

		v_values[v_size++] = value;
	}

	size_t size()
	{
		return v_size;
	}

	size_t capacity()
	{
		return v_capacity;
	}

	T& at(size_t index)
	{
		checkIndex(index);
		return v_values[index];
	}

	const T& at(size_t index) const
	{
		checkIndex(index);
		return v_values[index];
	}

private:
	T* v_values = nullptr;
	size_t v_size = 0;
	size_t v_capacity = 0;

	void copy(T* arr_from, T* arr_to, size_t size) {
		for (size_t i = 0; i < size; ++i) {
			arr_to[i] = arr_from[i];
		}
	}

	void checkIndex(size_t index)
	{
		if (index >= v_size)
		{
			throw std::out_of_range("Index is out of range");
		}
	}
};

template<class T>
void printVector(MyVector<T>& vect)
{
	std::cout << "capacityOfVector = " << vect.capacity() << std::endl;
	std::cout << "sizeOfVector = " << vect.size() << std::endl;

	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect.at(i) << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;
};