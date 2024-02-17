#include <iostream>

template <class T>
class My_smptr {
    T* ptr = nullptr;    

public:    

    My_smptr(T* argptr) {       
        delete this->ptr;
        this->ptr = argptr;       
    }

    T* release() {
        T* a = this->ptr;
        this->ptr = nullptr;
        std::cout << "\nResource released\nNew ptr adress: " << ptr << "\n";
        return a;    
    }

    T& operator *() {
        return *ptr;
    }

    T& operator *() const{        
        return *ptr;
   }   
    

    My_smptr(const My_smptr& other) = delete;

    My_smptr operator = (const My_smptr& other) = delete;

    ~My_smptr() {        
        std::cout << "Destructor called\n";
        delete this->ptr;
    }
};

int main()
{    
    int a = 5, c =15;
    int* f = new int(a);
    int* d = new int(c);
    int* k = new int(0);

    std::cout << "\n" << *f << "\n";

   My_smptr<int> r(f);
   //My_smptr<int> o(r);   // - отладочный код, оставлен как пример того, что работает запрет копирования
   My_smptr<int> o(d);
   int b = *r + 2;

   //r = o;               // - отладочный код, оставлен как пример того, что работает запрет оператора присваивания

   std::cout << "\n" << b << "\n";
   k = r.release();
   std::cout << "k = " << k << "\n";
   std::cout << "*k = " << *k << "\n";   
   
   delete k;

   return 0;
}
