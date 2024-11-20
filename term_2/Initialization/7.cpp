#include <iostream>
#include <string>

using std::cout , std::endl;

class Cat
{
private:
    int& miceCaughtgroup ;
public:

    Cat(int& a) : miceCaughtgroup(a) {}

    void catchMice(int count) 
    {
        miceCaughtgroup += count;
    }
};

int main()
{
 int miceCaughtA = 0;
 int miceCaughtB = 0;
 Cat alice(miceCaughtA), alex(miceCaughtA), anna(miceCaughtA);
 Cat bob(miceCaughtB), bella(miceCaughtB);
 alice.catchMice(2);
 alex.catchMice(1);
 bella.catchMice(4);
 bob.catchMice(2);
 anna.catchMice(1);
 bella.catchMice(1);
 alex.catchMice(4);
 bella.catchMice(5);
 alice.catchMice(2);
 cout << miceCaughtA << endl; // Должно напечатать 10
 cout << miceCaughtB << endl; // Должно напечатать 12
}