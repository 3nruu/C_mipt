#include <iostream>
#include <list>

using std::cout , std::endl , std::list;

void pr(int m , int n)
{
    list<int> war;

    for (int i = 1; i <= n; i++)
    {
        war.push_back(i);
    }

    list<int>::iterator it = war.begin();



    while (war.size() > 1)
    {
        for (int i = 1; i < m; i++)
       {
        it++;
        if (it == war.end()) 
        {
                it = war.begin(); 
       }
       }
    
        cout << *it << " " ;
        it = war.erase(it); 
        if (it == war.end()) 
        {
            it = war.begin(); 
        }


    }

    cout << "\n" << war.front() << endl;
    
}

int main()
{
    int n = 21;
    int m = 6;

    pr(m , n);
}