//#include "Vector.h"
//
//template <class T>
//Vector<T>::Vector() : size{}
//{
//	capacity = 2;
//	array = new T[capacity]{};
//}
//
//template<class T>
//Vector<T>::Vector(size_t size) : size{ size }
//{
//	capacity = size + size / 2;
//	array = new T[capacity]{};
//}
//
//template<class T>
//Vector<T>::Vector(const Vector<T>& v) : size{ v.size }
//{
//	capacity = size + size / 2;
//	array = new T[capacity]{};
//
//	for (int i = 0; i < size; i++)
//		array[i] = v.array[i];
//}
//
//template<class T>
//Vector<T>::~Vector() { if (array) delete[] array; }
//
//
