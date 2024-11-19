#include <iostream>
#include <string>

void truncateToDot(std::string& s)
{
    int t = s.find(".");
    s.erase(t,s.size());
    s.shrink_to_fit();
}


int main()
{
    std::string s1 = "cat.dog.mouse.elephant.tiger.lion";
    truncateToDot(s1);
    std::cout << s1 << std::endl;

    std::string s2 = "wikipedia.org";
    truncateToDot(s2);
    std::cout << s2 << std::endl;

    std::string s3 = ".com";
    truncateToDot(s3);
    std::cout << s3 << std::endl;



    return 0;
}