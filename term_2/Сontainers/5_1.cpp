#include <iostream>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::set<int> cuts;
    std::multiset<int> lengths;

    cuts.insert(0);
    cuts.insert(n);
    lengths.insert(n);

    for (int i = 0; i < k; ++i) {
        int cut;
        std::cin >> cut;

        auto it_right = cuts.upper_bound(cut);
        auto it_left = std::prev(it_right);

        //std::cout << "r" << *it_right << "l " << *it_left << std::endl;

        int left = *it_left;
        int right = *it_right;
        int length = right - left;

        lengths.erase(lengths.find(length));
        lengths.insert(cut - left);
        lengths.insert(right - cut);

        cuts.insert(cut);

        std::cout << *lengths.rbegin() << " ";

    }

    return 0;
}
