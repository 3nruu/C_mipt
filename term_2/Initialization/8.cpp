#include <iostream>
#include <cstring>
#include "stringmipt.hpp"
using namespace mipt;
using std::cout , std::endl;

int main()
{
    String a("Cat");
    cout << a << endl;


    String* b = new String("Dog");
    cout << *b << endl;
    delete b;

    alignas(String) char t[sizeof(String)];
    String* c = new(t) String("Elephant");
    cout<< *c <<endl;

    c->~String();

    return 0;

}