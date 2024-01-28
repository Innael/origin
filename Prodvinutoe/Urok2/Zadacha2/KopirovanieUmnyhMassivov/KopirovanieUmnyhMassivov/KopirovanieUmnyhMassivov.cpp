#include <iostream>
#include <windows.h>

class Full_Arrey : public std::exception {
public:
    const char* what() const override { return "Массив переполнен\n"; };
};

class Wrong_Index : public std::exception {
public:
    const char* what() const override { return "Неверный индекс\n"; };
};

class smart_arrey {
private:
    int size = 1;
    int step = 0;
    int* arr = new int[size];

public:
    smart_arrey(int size) {
        this->size = size;
        this->arr = new int[size + 1] {};
    }
    int& operator[](int index) {
        return arr[index];
    }

    smart_arrey& operator = (smart_arrey& new_arr) {
        this->size = new_arr.get_size();
        this->step = new_arr.get_step();
        delete[] this->arr;
        this->arr = new int[size];
        for (int i = 0; i < size; ++i) {
           this->arr[i] = new_arr.get_element(i);
        }
        return *this;
    }

    int& get_element(int index) {
        if (index < 0 || index >= size) throw Wrong_Index();
        return arr[index];
    }

    int get_size() {
        return size;
    }

    int get_step() {
        return step;
    }

    void add_element(int value) {
        if (step >= size) throw Full_Arrey();
        arr[step] = value;
        ++step;
    }
    ~smart_arrey() {
        delete[] this->arr;       
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    

    smart_arrey arr(5);
    smart_arrey new_arrey(2);

    try {
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        new_arrey.add_element(44);
        new_arrey.add_element(34);
    }
    catch (const Full_Arrey& ex) {
        std::cout << ex.what() << std::endl;
    }
    

    arr = new_arrey;

    try {
        for (int i = 0; i < 2; ++i) {
            std::cout << arr.get_element(i) << " ";
        }
    }
    catch (const Wrong_Index& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}