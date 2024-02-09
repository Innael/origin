#include <iostream>
#include <windows.h>

class Wrong_Index : public std::exception {
public:
    const char* what() const override { return "Неверный индекс\n"; };
};



template <class T> class Svoy_vector{
    T* arr = nullptr;
    int f_size = 0;
    int l_size = 0;
public:
    Svoy_vector() {
        arr = new T[10]{};
        f_size = 10;
        l_size = 5;
    }

    Svoy_vector<T>(const Svoy_vector& vec) {
        this->f_size = vec.f_size;
        this->l_size = vec.l_size;
        this->arr = new T[this->f_size];        
            for (int i = 0; i < l_size; ++i) {
                this->arr[i] = vec.at(i);
            }        
    }

    T& operator[](int index) {
        if (index > 0 || index < l_size) {
            return arr[index];
        }
        else throw Wrong_Index();
    }


    Svoy_vector<T>& operator = (Svoy_vector<T>& new_vec) {
        this->f_size = new_vec.f_size;
        this->l_size = new_vec.l_size;
        delete[] this->arr;
        this->arr = new T[f_size];
        for (int i = 0; i < l_size; ++i) {
            this->arr[i] = new_vec.at(i);
        }
        return *this;
    }

    T at(int index)  {
        if (index < 0 || index >= l_size) {
            throw Wrong_Index();
        }
        else return arr[index];
    }

    T at(int index) const {
        if (index >= 0 && index < l_size) {
            return arr[index];
        }
        else throw Wrong_Index();
    }

    void push_back(T value) {
        if (l_size < f_size) {
            arr[l_size] = value;
            ++l_size;
        }
        else {
            T* arrt = new T[f_size * 2] {};
            for (int i = 0; i < f_size; ++i) {
                arrt[i] = arr[i];
            }
            delete[] arr;
            arrt[l_size] = value;
            this->arr = new T[f_size * 2]{};
            for (int i = 0; i < l_size+1; ++i) {
                arr[i] = arrt[i];
            }
            this->l_size +=1;
            this->f_size *= 2;
            delete[] arrt;
        }
    }

    int size() {
        return l_size;
    }       

    int capacity() {
        return (f_size - l_size);
    }

    ~Svoy_vector(){
        delete[] this->arr;
    }
};

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Hello World!\n";
    
    try {
        Svoy_vector<int> vec;
        std::cout << vec.at(2) << "\n";
    }
    catch (const Wrong_Index & ex) {
        std::cout << ex.what() << std::endl;
    }  
    
    Svoy_vector<int> vec;

    for (int i = 0; i < 5; ++i) {
        vec[i] = i * i;
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << vec[i] << " ";
    }

    Svoy_vector<int> vec2;
    vec2 = vec;

    std::cout << "\nvec2: ";

    for (int i = 0; i < 5; ++i) {
        std::cout << vec2[i] << " ";
    }

    vec2.push_back(75);


    Svoy_vector<int> vec3(vec2);

    std::cout << "\nvec3: ";

    for (int i = 0; i < 6; ++i) {
        std::cout << vec3[i] << " ";
    }

    for (int i = 5; i < 27; ++i) {
        vec3.push_back(i);
    }

    std::cout << "\nvec3: ";

    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }

    std::cout << "\nvec3, осталось места: "  << vec3.capacity();

    return 0;
}


