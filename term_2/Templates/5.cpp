#include <iostream>
#include <cstring> 
#include <algorithm>

template <typename T>

void swapEndianness(T& x)
{
    unsigned char t[sizeof(T)];
    std::memcpy(t , &x , sizeof(T));

    int s = sizeof(T);
    for (int i = 0; i < s/2 ; i++)
    {
        std::swap(t[i] , t[s - i - 1]);
    }

    std::memcpy(&x , t , sizeof(T));
}





int main()
 {
 std::cout << std::hex;
 int a = 0x1a2b3c4d;
 std::cout << a << std::endl; // Должен напечатать 1a2b3c4d
 swapEndianness(a);
 std::cout << a << std::endl; // Должен напечатать 4d3c2b1a
 swapEndianness(a);
 std::cout << a << std::endl; // Должен напечатать 1a2b3c4d
 short b = 0x1a2b;
 std::cout << b << std::endl; // Должен напечатать 1a2b
 swapEndianness(b);
 std::cout << b << std::endl; // Должен напечатать 2b1a
 }
