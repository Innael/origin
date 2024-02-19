#include <iostream>
#include <vector>

template <class T >
void move_vectors(std::vector<T>& A, std::vector<T>& B) {
    std::vector<T> Tmp{};
    Tmp = std::move(A);
    A = std::move(B);
    B = std::move(Tmp);    
}


int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two = {"grass green", "water wet", "sky blue" };
    std::vector <int> tree = { 3, 3, 3 };
    std::vector <int> stone = { 100, 10000, 1000000 , 100000000 };

    move_vectors(one, two);
    move_vectors(tree, stone);

    std::cout << "one now = ";
    for (auto& const elem : one) {
        std::cout << elem << " ";
    }
    std::cout << "\ntwo now = ";
    for (auto& const elem : two) {
        std::cout << elem << " ";
    }

    std::cout << "\ntree now = ";
    for (auto& const elem : tree) {
        std::cout << elem << " ";
    }
    std::cout << "\nstone now = ";
    for (auto& const elem : stone) {
        std::cout << elem << " ";
    }

    return 0;
}


