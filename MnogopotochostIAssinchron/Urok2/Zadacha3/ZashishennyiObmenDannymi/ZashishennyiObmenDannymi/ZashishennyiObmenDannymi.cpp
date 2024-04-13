#include <iostream>
#include <mutex>
#include <thread>

class Data {
public:
    std::mutex mtx;
    int s_field_a = 0;
    int s_field_b = 0;
};

void swap1(Data& a, Data& b) {
    Data temp;
    std::lock(a.mtx, b.mtx); // не понятно, как спользовать одновременно с lock_guard
    //std::lock_guard<std::mutex> grd_a(a.mtx); с этой строчкой возникает C26111 "Вызывающему не удаётся снять блокировку с a -> mtx"
    //std::lock_guard<std::mutex> grd_b(b.mtx); с этой строчкой возникает C26111 "Вызывающему не удаётся снять блокировку с b -> mtx"
    temp.s_field_a = std::move(a.s_field_a);
    temp.s_field_b = std::move(a.s_field_b);
    a.s_field_a = std::move(b.s_field_a);
    a.s_field_b = std::move(b.s_field_b);
    b.s_field_a = std::move(temp.s_field_a);
    b.s_field_b = std::move(temp.s_field_b);
    a.mtx.unlock();   // - в таком виде, вроде работает
    b.mtx.unlock();
}

void swap2(Data& a, Data& b) {
    Data temp;
    std::scoped_lock lock(a.mtx, b.mtx);    
    temp.s_field_a = std::move(a.s_field_a);
    temp.s_field_b = std::move(a.s_field_b);
    a.s_field_a = std::move(b.s_field_a);
    a.s_field_b = std::move(b.s_field_b);
    b.s_field_a = std::move(temp.s_field_a);
    b.s_field_b = std::move(temp.s_field_b);   
}

void swap3(Data& a, Data& b) {
    Data temp;
    std::unique_lock<std::mutex>  mLG1(a.mtx, std::defer_lock);
    std::unique_lock<std::mutex>  mLG2(b.mtx, std::defer_lock);
    std::lock(mLG1, mLG2);
    temp.s_field_a = std::move(a.s_field_a);
    temp.s_field_b = std::move(a.s_field_b);
    a.s_field_a = std::move(b.s_field_a);
    a.s_field_b = std::move(b.s_field_b);
    b.s_field_a = std::move(temp.s_field_a);
    b.s_field_b = std::move(temp.s_field_b);
    mLG1.unlock();
    mLG2.unlock();
}

void tricky_program(Data& a, Data& b) {
    std::thread::id id = std::this_thread::get_id();
    swap1(a, b);
    std::cout << "Tread: " << id << " Swap\n\n";
    swap2(a, b);
    std::cout << "Tread: " << id << " Swap\n\n";
    swap3(a, b);
    std::cout << "Tread: " << id << " Swap\n\n";
}


int main()
{
    Data d1, d2;
    d1.s_field_a = 5;
    d1.s_field_b = 7;
    d2.s_field_a = 182;
    d2.s_field_b = 153;
    

    std::cout << "d1:a = " << d1.s_field_a << "  d1:b = " << d1.s_field_b << "\n";
    std::cout << "d2:a = " << d2.s_field_a << "  d2:b = " << d2.s_field_b << "\n\n";

    std::cout << "Using swap1\n";

    swap1(d1, d2);

    std::cout << "d1:a = " << d1.s_field_a << "  d1:b = " << d1.s_field_b << "\n";
    std::cout << "d2:a = " << d2.s_field_a << "  d2:b = " << d2.s_field_b << "\n\n";

    std::cout << "Using swap2\n";

    swap2(d1, d2);

    std::cout << "d1:a = " << d1.s_field_a << "  d1:b = " << d1.s_field_b << "\n";
    std::cout << "d2:a = " << d2.s_field_a << "  d2:b = " << d2.s_field_b << "\n\n";

    std::cout << "Using swap3\n";

    swap3(d1, d2);

    std::cout << "d1:a = " << d1.s_field_a << "  d1:b = " << d1.s_field_b << "\n";
    std::cout << "d2:a = " << d2.s_field_a << "  d2:b = " << d2.s_field_b << "\n\n";


    std::thread t1(tricky_program, std::ref(d1), std::ref(d2));
    std::thread t2(tricky_program, std::ref(d1), std::ref(d2));
    std::thread t3(tricky_program, std::ref(d1), std::ref(d2));
    t1.join();
    t2.join();
    t3.join();

    std::cout << "Something very clever happened\n";

    std::cout << "d1:a = " << d1.s_field_a << "  d1:b = " << d1.s_field_b << "\n";
    std::cout << "d2:a = " << d2.s_field_a << "  d2:b = " << d2.s_field_b << "\n";


    return 0;
}

