#include <string>
#include <cctype> 
#include <iostream>

 std::string repeat1(const std::string& s)
 {
    return s + s;
 }

 void repeat2(std::string& s)
 {
    std::string t = s;

    s = t + t;
 }

  void repeat3(std::string* ps)
  {
    std::string t = *ps;

    *ps = t + t;
  }

std::string* repeat4(const std::string& s)
{
    std::string* result = new std::string (s + s);

    return result;
}

int main()
{
    std::string S = "Cat";
    std::cout<<repeat1(S)<<std::endl;

    repeat2(S);
    std::cout<<S<<std::endl;


    std::string* s = &S;
    repeat3(s);
    std::cout<<S<<std::endl;

    std::cout<<*repeat4(S)<<std::endl;



    return 0;
}
