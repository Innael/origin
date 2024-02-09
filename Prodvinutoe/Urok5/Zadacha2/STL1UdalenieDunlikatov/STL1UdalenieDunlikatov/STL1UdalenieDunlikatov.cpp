#include <iostream>
#include <set>
#include <vector>

int main()
{
    int c = 0, d = 0, sv = 0;
    std::set<int> my_set{};
    std::vector<int> vec{};

    while (c < 2) {
        std::cout << "Please enter count of numbers (at least two) : ";
        std::cin >> c;
        std::cout << " " << std::endl;
    }
    std::cout << "Please enter a series of numbers: \n";

    std::cout << "[IN] : \n";

    for (int i = 0; i < c; ++i) {
        std::cin >> d;
        my_set.insert(d);
    }
    
    std::cout << "[OUT]: \n";

    for (const auto& elem : my_set) {
        vec.push_back(elem);
    }

    sv = vec.size();

    for (int i = sv - 1; i >=0; --i) {
        std::cout << vec[i] << "\n";
    }

    return 0;
}


