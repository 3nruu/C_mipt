#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <utility>
using std::cout, std::endl;

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (size_t i = 0; i < v.size() - 1; ++i)
        out << v[i] << ", ";

    if (!v.empty())
    {
        out << v.back();
    }
    out << "]";
    return out;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}


// Нужно написать функцию pairing
template <typename Container>
std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairing(const Container& container)
{
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> result;
    auto it = container.begin();

    while (it != container.end()) {
        typename Container::value_type first = *it;
        ++it;

        typename Container::value_type second = (it != container.end()) ? *it : typename Container::value_type();
        result.push_back(std::make_pair(first, second));

        if (it != container.end()) {
            ++it;
        }
    }

    return result;
}


int main()
{
    std::vector a {10, 20, 30, 40, 50, 60};
    cout << pairing(a) << endl;


    std::list<std::string> b {"cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf"};
    cout << pairing(b) << endl;


    std::string c {"Cats and dogs!"};
    cout << pairing(c) << endl;
}


/*
    Программа должна напечатать:

    [(10, 20), (30, 40), (50, 60)]
    [(cat, dog), (mouse, elephant), (tiget, axolotl), (wolf, )]
    [(C, a), (t, s), ( , a), (n, d), ( , d), (o, g), (s, !)]
*/