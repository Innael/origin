#include <iostream>
#include <vector>

template <class T>
T my_sqrt(T & a) {
    return a * a;
}

template<class T>
std::vector<T> my_sqrt(std::vector<T> & vec) {
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        vec[i] *= vec[i];
    }        
    return vec;
}

int main()
{     
    int a = 4;
    std::vector<int> vec{ -1, 4 , 8, 7, 5, 9 };

    std::cout << "[IN]: " << a << "\n";
    std::cout << "[OUT]: " << my_sqrt(a) << "\n";
    std::cout << "[IN]:";
    for (int i : vec) {
        std::cout << " " << i ;
    }
    std::cout << "\n";

    std::vector<int> vec2 = my_sqrt(vec);

    std::cout << "[OUT]:";
    for (int i : vec2) {
        std::cout << " " << i ;
    }

    return 0;
}




