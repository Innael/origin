#include <iostream>
#include <vector>

class my_functor {
    int counter = 0; //- За ненадобностью, в получившейся реализации, считает, сколько раз обратимся к полю данных по индексу.
    std::vector<int> data1{};
public:
    my_functor() {
        int c = 0, d = 0;
        while (c < 2) {
            std::cout << "Please enter count of numbers (at least two) : ";
            std::cin >> c;
            std::cout << " " << std::endl;
        }
        std::cout << "Please enter a series of numbers: ";

        for (int i = 0; i < c; ++i) {            
            std::cin >> d;
            data1.push_back(d);
        }
    }
    int get_size() {
        return data1.size();
    }
    int get_element(int index) {
        if (index > 0 || index <= data1.size()) {
            return data1[index];
        }
        else {
            std::cout << "\n Wrong index in my_functor data1 vector\n";
            return 0;
        }
    }
    int get_sum() {
        int sum = 0;
        for (int i = 0; i < data1.size(); ++i) {
            sum += data1[i];
        }
        return sum;
    }
    int get_count() {  
        int count = 0;
        for (int i = 0; i < data1.size(); ++i) {
            if ((data1[i] % 3) == 0) {
                ++count;
            }
        }
        return count;
    }

    int operator() (int index) {
        counter++;
    }
};

int main()
{
    my_functor test;
    std::cout << "[IN]: ";
    for (int i = 0; i < test.get_size();++i) {
        std::cout << test.get_element(i) << " ";
    };
    std::cout << "\n[OUT]: get_sum() = " << test.get_sum();
    std::cout << "\n[OUT]: get_count() = " << test.get_count();
    return 0;
}

