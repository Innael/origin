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


    Tabl<T>(const Tabl<T>& tb) {}
       
    

    Tabl& operator = (Tabl& tb) {
        for (int i = 0; i < this->stb; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        this->stk = tb.get_stk();
        this->stb = tb.get_stb();
        this->matrix = new T * [stb];
        for (int i = 0; i < stb; ++i) {
            this->matrix[i] = new T[stk];
        }
        for (int j = 0; j < stb; ++j) {
            for (int i = 0; i < stk; ++i) {
                this->matrix[j][i] = tb.get_element(j, i);
            }
        }
        return *this;
    }

    int Size() const{
        return stb * stk;
    }   

    int get_stk() {
        return stk;
    }

    int get_stb() {
        return stb;
    }

    T& get_element(int index1, int index2) {
        return matrix[index1][index2];
    }

    T* operator[](int index) {
        if (index >= 0 && index < stk) {
            return matrix[index];
        }
        else std::cout << "Array out of bounds\n";
        return 0;
    }  

    T* operator[](int index) const {
        if (index >= 0 && index < stk) {
            return matrix[index];
        }
        else std::cout << "Array out of bounds\n";
        return 0;
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

    Tabl<double> t1(2, 3);
    Tabl<double> t3(3, 4);
    t3 = t1;
    Tabl<double> t4(t1);

    return 0;
}

