#include <iostream>
 #include <string>
 #include <vector>



std::string concatenate(const std::vector<std::string>& v) 
{
    std::string result;
    for (int i = 0 ; i < v.size() ; i++) 
    {
        result += v[i];
    }
    return result;
}



 int main()
 {
 std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
 std::cout << concatenate(v) << std::endl; // Должно напечатать CatDogMouseTigerElk
 }