#pragma once
#include "Vector.h"

template <class T>
Vector<T>::Vector() : size{}
{
	capacity = 2;
	array = new T[capacity]{};
}

template<class T>
Vector<T>::Vector(size_t size) : size{ size }
{
	capacity = size + size / 2;
	array = new T[capacity]{};
}

template<class T>
Vector<T>::Vector(const Vector<T>& v) : size{ v.size }
{
	capacity = size + size / 2;
	array = new T[capacity]{};

	for (int i = 0; i < size; i++)
		array[i] = v.array[i];
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (array) delete[] array;
	size = v.size;
	capacity = size + size / 2;
	array = new T[capacity]{};

	for (int i = 0; i < size; i++)
		array[i] = v.array[i];
}

template<class T>
inline T Vector<T>::At(size_t index)
{
	assert(index < 0 || index >= size);
	return array[index];
}

template<class T>
inline T& Vector<T>::operator[](size_t index)
{
	return array[index];
}

template<class T>
inline T Vector<T>::Front()
{
	return array[0];
}

template<class T>
inline T Vector<T>::Back()
{
	return array[size - 1];
}

template<class T>
inline T* Vector<T>::Data()
{
	return array;
}

template<class T>
inline bool Vector<T>::IsEmpty()
{
	return size == 0;
}

template<class T>
inline size_t Vector<T>::Size()
{
	return size;
}

template<class T>
inline size_t Vector<T>::Capacity()
{
	return capacity;
}

template<class T>
inline void Vector<T>::Shrink()
{
	capacity = size;
	T* arrayNew = new T[capacity];
	
	for (int i = 0; i < size; i++)
		arrayNew[i] = array[i];
	delete[] array;

	array = arrayNew;
}

template<class T>
inline void Vector<T>::Reserve(size_t new_cap)
{
	if (new_cap > capacity)
	{
		capacity = new_cap;
		T* arrayNew = new T[capacity];

		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];

		delete[] array;

		array = arrayNew;
	}
}

template<class T>
inline void Vector<T>::Clear()
{
	/*if (array) delete[] array;
	size = 0;
	capacity = 2;
	array = new T[capacity];*/
	size = 0;
}

template<class T>
inline void Vector<T>::PushBack(T value)
{
	if (size >= capacity)
		Reserve(capacity + size / 2);
	array[size++] = value;
}

template<class T>
inline void Vector<T>::PushFront(T value)
{
	if (size >= capacity)
		Reserve(capacity + size / 2);
	for (int i = size - 1; i >= 0; i--)
		array[i + 1] = array[i];
	array[0] = value;
	size++;
}

template<class T>
inline void Vector<T>::Insert(size_t index, T value)
{
	if (size >= capacity)
		Reserve(capacity + size / 2);
	if (index <= 0)
	{
		PushFront(value);
		return;
	}
	if (index >= size)
	{
		PushBack(value);
		return;
	}
	for (int i = size - 1; i >= index; i++)
		array[i + 1] = array[i];
	array[index] = value;
	size++;
}

template<class T>
inline T Vector<T>::PopBack()
{
	T value = array[--size];
	if (capacity > (size + size / 2))
		Reserve(size + size / 2);
	return value;
}

template<class T>
inline T Vector<T>::PopFront()
{
	T value = array[0];
	for (int i{}; i < size - 1; i++)
		array[i] = array[i + 1];
	if (capacity > (size + size / 2))
		Reserve(size + size / 2);
	size--;
	return value;
}

template<class T>
inline T Vector<T>::Remove(size_t index)
{
	if (index <= 0)
		return PopFront();
	if (index >= size)
		return PopBack();

	T value = array[index];
	for (int i{ index }; i < size - 1; i++)
		array[i] = array[i + 1];
	if (capacity > (size + size / 2))
		Reserve(size + size / 2);
	return value;
}

template<class T>
Vector<T>::~Vector() { if (array) delete[] array; }


