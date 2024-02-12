#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void sieve(std::vector<int>& vc) {
    std::vector<int> vc2{};
    std::sort(vc.begin(), vc.end(),
        [](const int& lhs, const int& rhs) {
            return lhs < rhs;
        }
    );
    int a = vc[0];
    vc2.push_back(a);
    for (const auto& elem : vc) {       
        if (elem != a) {
            vc2.push_back(elem);
        }
        a = elem;
    }
    vc = vc2;
}

void sieve2(std::vector<int>& vc) {
    std::set<int> set1{};    
    
    for (const auto& elem : vc) {
        set1.insert(elem);
    }
   
    for (const auto& elem : vc) {
        vc.pop_back();
    }

    for (const auto& elem : set1) {
        vc.push_back(elem);
    }

}

int main()
{
    std::vector<int> vec{ 1,2,3,4,3,3,27,7,2,15,43,8,1,8 };
    std::cout << "[IN]: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    sieve(vec);
    

    std::cout << "[OUT]: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }

    std::cout << "\n\n";

    std::vector<int> vec2{ 232,1,4542,577,3,3,577,4542,31,3,2,31,17,8,1,54 };
        
    std::cout << "[IN]: ";
    for (const auto& elem : vec2) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    sieve2(vec2);

    std::cout << "[OUT]: ";
    for (const auto& elem : vec2) {
        std::cout << elem << " ";
    }

    return 0;
}

