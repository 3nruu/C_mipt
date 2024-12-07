#include <iostream>
#include <map>
#include <vector>


int main()
{
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> numbers[i];
    }

    std::map<int , int> m;
    for (int num : numbers)
    {
        m[num]++;
    }

    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) 
    {
        std::cout <<  it->first<<" "<< it->second << " \n";
    }


    return 0;
}