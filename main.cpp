#include "UniquePtr.h"
#include <iostream>

int main()
{
    char* data = new char[128];
    UniquePtr ptr(data);
    std::cout << "ptr = " << ptr << std::endl;
    UniquePtr p1;
    UniquePtr p2(std::move(p1));
    std::cout << "p2 = " << p2 << std::endl;
    p2 = std::move(p1);
    std::cout << "p1 = " << p1 << " p2 = " << p2 << std::endl;
    UniquePtr p3(nullptr);
    std::cout << "p3 = " << p3 << std::endl;
    p3 = UniquePtr(nullptr);
    std::cout << "p3 = " << p3 << std::endl;
}