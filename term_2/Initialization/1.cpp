#include <string>
#include <cctype> 
#include <iostream>


std::string changeFirstLetterCase(const std::string& str) 
{
    std::string result = str; 

    if (std::islower(result[0])) {
        result[0] = std::toupper(result[0]);
    } else if (std::isupper(result[0])) {
        result[0] = std::tolower(result[0]); 
    }

    return result;
}


int main() 
{
    std::cout << changeFirstLetterCase("Cat") << std::endl; 
    std::cout << changeFirstLetterCase("dog") << std::endl; 

    return 0;
}