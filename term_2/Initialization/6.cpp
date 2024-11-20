#include <iostream>
#include <string>
using std::cout , std::endl , std::string;

int main()
{
    int* a = new int(123);
    cout<<*a<<endl;
    delete a;

    string* s = new string("Cats and Dogs");
    cout<<*s<<endl;
    delete s;

    int* A = new int[5]{10 , 20 , 30 , 40 , 50};
    for(int i = 0 ; i<5 ; i++)
    {
    cout<<A[i]<<endl;
    }
    delete[] A;

    string* S = new string[3]{"Cat" , "Dog" , "Mouse"};
    for(int i = 0 ; i<3 ; i++)
    {
    cout<<S[i]<<endl;
    }
    
    std::string_view* SS = new std::string_view[3]{S[0] , S[1] , S[2]};
    for (int i = 0; i < 3; ++i) 
    {
        cout << SS[i] <<endl;
    }

    delete[] S;
    delete[] SS;

    return 0;
}
