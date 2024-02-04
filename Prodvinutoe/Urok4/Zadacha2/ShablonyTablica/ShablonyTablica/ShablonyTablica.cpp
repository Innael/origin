#include <iostream>

template <class T>
class Tabl {
    int stk = 0, stb = 0;
    T** matrix = nullptr;       

public:
    Tabl(int a, int b) {
        stb = a, stk = b;
        matrix = new T* [stb];
        for (int i = 0; i < stb; ++i) {
            matrix[i] = new T[stk];
        }        
    }
    int Size() const{
        return stb * stk;
    }   

    T* operator[](int index) {
        if (index >= 0 && index < stk) {
            return matrix[index];
        }
        else std::cout << "Array out of bounds\n";
    }  

    T* operator[](int index) const {
        if (index >= 0 && index < stk) {
            return matrix[index];
        }
        else std::cout << "Array out of bounds\n";
    }

    ~Tabl() {

        for (int i = 0; i < stb; ++i) {
            delete[] this->matrix[i];
        }

        delete[] this->matrix;
    }
};

int main()
{
    int a = 4, b = 5, t = 0;

    auto test = Tabl<int> (a, b);
    
    for (int j = 0; j < a; ++j) {
        for (int i = 0; i < b; ++i) {
            test[j][i] = i + t;
            
        }
        ++t;
    }

    test[0][0] = 4;    
    std::cout << test.Size() << "\n";

    for (int j = 0; j < a; ++j) {
        for (int i = 0; i < b; ++i) {
            std::cout << test[j][i] << " ";
        }
        std::cout << "\n";
    }    
}

