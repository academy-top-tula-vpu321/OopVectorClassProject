#pragma once
template <typename T>
class VectorIterator;


template <typename T>
class Vector
{
	T* array;
	int size;
	int capacity;
public:
	Vector();
	Vector(size_t size);
	Vector(const Vector<T>& v);

	Vector<T>& operator=(const Vector<T>& v);

	T At(size_t index);
	T& operator[](size_t index);

	T Front();
	T Back();
	T* Data();

	bool IsEmpty();
	size_t Size();
	size_t Capacity();
	void Shrink();
	void Reserve(size_t new_cap);

	void Clear();
	void PushBack(T value);
	void PushFront(T value);
	void Insert(size_t index, T value);

	T PopBack();
	T PopFront();
	T Remove(size_t index);

	void Resize(size_t size);
	void Resize(size_t size, T value);

	VectorIterator<T> Iterator();


	~Vector();
};

template <typename T>
class VectorIterator
{
	Vector<T>* container;
	int index;
public:
	VectorIterator(Vector<T>* container)
		: container{ container }, index{ -1 } {}
	~VectorIterator() {};

	void SetBegin();
	bool Next();
	T Current();

	bool IsEnd();
};

#include "Vector.inl"
