#include <iostream>
#include <set>

int main()
{
    int n;
    std::cin >> n;

    std::multiset<int> numbers;
    for (int i = 0; i < n; ++i) {
        int number;
        std::cin >> number;
        numbers.insert(number); 
    }

    for (const int& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}


