#include <iostream>
 #include <string>


void addBrackets(std::string& str)
{
    str.push_back(']');
    str.insert(0 , "[");
}




 int main()
 {
 std::string a = "Cat";
 addBrackets(a);
 std::cout << a << std::endl; // Должно напечатать [Cat]
 addBrackets(a);
 std::cout << a << std::endl; // Должно напечатать [[Cat]]
 }