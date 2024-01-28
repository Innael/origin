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
        if (index > 0 || index < size) {
            return arr[index];
        }
    }    
    int get_element(int index) {
        if (index < 0 || index >= size) throw Wrong_Index();
        return arr[index];
    }
   void add_element(int value){
       if (step >= size) throw Full_Arrey();
        arr[step] = value;
        ++step;
    }
   ~smart_arrey() {
       delete[] arr;      
   }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sz = 0;

    while (sz < 1) {
        std::cout << "Введите размер создаваемого массива: ";
        std::cin >> sz;
        if (sz < 1) {
            std::cout << "Размер массива не может быть меньше одного элемента." << std::endl;
        }
    }
    
    smart_arrey ar(sz);
    
    try {        
        ar.add_element(11);
        ar.add_element(12);
        ar.add_element(122);
        ar.add_element(43);
        ar.add_element(7000329);
        ar.add_element(44);
        ar.add_element(29);
        ar.add_element(3);

        std::cout << ar.get_element(5) << "\n";
    }
    catch(const Full_Arrey& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (const Wrong_Index& ex) {
        std::cout << ex.what() << std::endl;
    }

        for (int i = 0; i < sz; ++i) {
            std::cout << ar.get_element(i) << " ";
        }
    
    return 0;
}

