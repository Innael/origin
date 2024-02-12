#include <iostream>
#include <vector>
#include <list>
#include <set>

template<class T>
void print_k(T argument) {
    for (const auto& elem : argument) {
        std::cout << elem << " ";
    }
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_k(test_set); 
    std::cout << "\n";

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_k(test_list); 
    std::cout << "\n";

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_k(test_vector); 

    return 0;
}


