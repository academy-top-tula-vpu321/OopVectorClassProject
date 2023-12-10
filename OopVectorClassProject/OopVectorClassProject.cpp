#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> v;

    v.PushBack(100);
    v.PushBack(200);
    v.PushBack(300);

    for (int i{}; i < v.Size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    auto it = v.Iterator();
    while (it.Next())
        std::cout << it.Current() << " ";
    std::cout << "\n";
}
