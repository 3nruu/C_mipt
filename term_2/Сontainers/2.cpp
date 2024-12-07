 #include <iostream>
 #include <set>
 #include <vector>
 using std::cout , std::endl , std::set;

 void print_set(set<int>::iterator start, set<int>::iterator finish)
 {
    for (std::set<int>::iterator it = start; it != finish; ++it)
    {
        cout << *it << " ";
    }
 }


 int main()
 {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    set<int> un_numbers;

    for (int i = 0; i < n; i++)
    {
        un_numbers.insert(numbers[i]);
    }

    print_set(un_numbers.begin() , un_numbers.end());

    return 0;
 }