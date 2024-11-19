#include <iostream>
#include <string>

std::string operator*(const std::string& str, int n)
{
    std::string* res = new std::string[n*str.size()];

    for (int i = 0 ; i < n ; i++)
    {
        *res += str;
    }

    return *res;
}

std::string operator*(int n, const std::string& str) 
{
    return str * n; 
}

int main()
{
    std::string s = "Cat";
    std::cout << (s * 3) << std::endl;
    std::cout << (4 * s) << std::endl;

    return 0;
}