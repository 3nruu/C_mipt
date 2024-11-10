#include <iostream>
 #include <string>



bool isDomainName(const std::string& str) {
    return str.rfind("www.") == 0 && str.find(".com") == str.size() - 4;
}



 int main()
 {
 std::cout << isDomainName("www.google.com") << std::endl;
 std::cout << isDomainName("abc") << std::endl;
 std::cout << isDomainName("hello.com") << std::endl;
 }