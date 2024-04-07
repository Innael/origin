#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>

long long one_t(std::vector<int>& v1, std::vector<int>& v2) {
    
    long long sum = 0;

    if (v1.size() >= v2.size()) {
        for (int i = 0; i < v2.size(); ++i) {
            sum += v1[i] + v2[i];
        }
        for (int i = v2.size(); i < v1.size(); ++i) {
            sum += v1[i];
        }
        return sum;
    }
    if (v1.size() < v2.size()) {
        for (int i = 0; i < v1.size(); ++i) {
            sum += v1[i] + v2[i];
        }
        for (int i = v1.size(); i < v2.size(); ++i) {
            sum += v2[i];
        }
        return sum;
    }
    return sum;
}

void two_t(std::vector<int>& v1, std::vector<int>& v2, int it1, int it2, long long& ab) {

    long long sum = 0;

    if (v1.size() >= v2.size()) {
        for (int i = it1; i < (v2.size() - it2); ++i) {
            sum += v1[i] + v2[i];
        }
        for (int i = (v2.size() - it2); i < (v1.size() - it1) ; ++i) {
            sum += v1[i];
        }
        ab = sum;
    }
    if (v1.size() < v2.size()) {
        for (int i = it2; i < (v1.size() - it1); ++i) {
            sum += v1[i] + v2[i];
        }
        for (int i = (v1.size() - it1); i < (v2.size() - it2); ++i) {
            sum += v2[i];
        }
        ab = sum;
    }
}

void uni_t(std::vector<int>& v1, std::vector<int>& v2, int it1, int it2, int it3, int it4, long long& ab) {

    long long sum = 0;

    if (it3 >= it4) {     
               
        for (int i = 0; i < (it4 - it2); ++i) {
            sum += v1[it1+i] + v2[it2+i];
        }
        for (int i = it4; i < it3; ++i) {
            sum += v1[i];
        }     
        ab = sum;
        
    }
    if (it3 < it4) {
        for (int i = 0; i < (it3 - it1); ++i) {
            sum += v1[i+it1] + v2[i+it2];
        }
        for (int i = it3; i < it4; ++i) {
            sum += v2[i];
        }
        ab = sum;       
    }
}


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::vector <std::chrono::duration<double>> res_1t(4);
    std::vector <std::chrono::duration<double>> res_2t(4);
    std::vector <std::chrono::duration<double>> res_4t(4);
    std::vector <std::chrono::duration<double>> res_8t(4);
    std::vector <std::chrono::duration<double>> res_16t(4);

    std::vector <int> v3_1(1000, 1);
    std::vector <int> v3_2(1000, 2);

    std::vector <int> v4_1(10000, 3);
    std::vector <int> v4_2(10000, 4);
    std::vector <int> v4_s(10000);

    std::vector <int> v5_1(100000, 5);
    std::vector <int> v5_2(100000, 6);

    std::vector <int> v6_1(1000000, 7);
    std::vector <int> v6_2(1000000, 8);

    std::vector<std::vector<int>> vv = { v3_1, v4_1, v5_1, v6_1, v3_2, v4_2, v5_2, v6_2 };

    int tc = std::thread::hardware_concurrency();


    // 1 поток:
    for (int i = 0; i < 4; ++i) {
        long long s = 0;
        auto start = std::chrono::steady_clock::now();
        s = one_t(vv[i], vv[i + 4]);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> e_s = end - start;
        res_1t[i] = e_s;
        //std::cout << s << "\n";
    } 


    // 2 потока:            
    for (int i = 0; i < 4; ++i) {
        long long s = 0;
        long long a = 0;
        long long b = 0;
        {
            auto start = std::chrono::steady_clock::now();
            int it1 = 0, it2 = 0;
            std::thread t1(two_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, std::ref(a));

            it1 = (vv[i].size() / 2) ;
            if (vv[i].size() % 2 == 1) --it1;
            it2 = (vv[i+4].size() / 2 );     
            if (vv[i+4].size() % 2 == 1) --it2;

            std::thread t2(two_t, std::ref(vv[i]) , std::ref(vv[i+4]) , it1 , it2 , std::ref(b) );

            t1.join();
            t2.join();

            s = a + b;

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> e_s = end - start;
            res_2t[i] = e_s;
            //std::cout << s << "\n";
            s = 0;
            a = 0; 
            b = 0;
        }
    }    

    // 4 потока:
    for (int i = 0; i < 4; ++i) {
        long long s = 0;
        long long a = 0;
        long long b = 0;
        long long c = 0;
        long long d = 0;
        {
            auto start = std::chrono::steady_clock::now();            

            int it1 = 0, it2 = 0;

            int it3 = (vv[i].size() / 4);
            if ((vv[i].size() % 4) > 0) ++it3;
            
            int it4 = (vv[i + 4].size() / 4);
            if (vv[i + 4].size() % 4 > 0) ++it4;

            std::thread t1(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(a));

            it1 = it3;            
            it2 = it4;

            it3 += (vv[i].size() / 4);            
            if ((vv[i].size() % 4) > 1) ++it3;

            it4 += (vv[i + 4].size() / 4);            
            if (vv[i + 4].size() % 4 > 1) ++it4;

            std::thread t2(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(b));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 4);            
            if ((vv[i].size() % 4) > 2) ++it3;

            it4 += (vv[i + 4].size() / 4);            
            if (vv[i + 4].size() % 4 > 2) ++it4;

            std::thread t3(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(c));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 4);
            it4 += (vv[i + 4].size() / 4);           

            std::thread t4(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(d));

            t1.join();
            t2.join();
            t3.join();
            t4.join();


            s = a + b + c + d;

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> e_s = end - start;
            res_4t[i] = e_s;
            //std::cout << s << "\n";
            s = 0;
            a = 0;
            b = 0;
            c = 0;
            d = 0;
        }
    }      
            

    // 8 потоков:
    for (int i = 0; i < 4; ++i) {
        long long s = 0, a = 0 , b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
        {
            auto start = std::chrono::steady_clock::now();

            int it1 = 0, it2 = 0;

            int it3 = (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 0) ++it3;

            int it4 = (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 0) ++it4;

            std::thread t1(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(a));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 4) > 1) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 1) ++it4;

            std::thread t2(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(b));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 2) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 2) ++it4;

            std::thread t3(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(c));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 3) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 3) ++it4;

            std::thread t4(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(d));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 4) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 4) ++it4;

            std::thread t5(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(e));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 5) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 5) ++it4;

            std::thread t6(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(f));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            if ((vv[i].size() % 8) > 6) ++it3;

            it4 += (vv[i + 4].size() / 8);
            if (vv[i + 4].size() % 8 > 6) ++it4;

            std::thread t7(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(g));

            it1 = it3;
            it2 = it4;

            it3 += (vv[i].size() / 8);
            it4 += (vv[i + 4].size() / 8);

            std::thread t8(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(h));

            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
            t6.join();
            t7.join();
            t8.join();


            s = a + b + c + d + e + f + g +h;

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> e_s = end - start;
            res_8t[i] = e_s;
            //std::cout << s << "\n";           
        }
    }

    //16 потоков
    for (int i = 0; i < 4; ++i) {
        long long s = 0;        
        std::vector<long long> var(16);
        std::vector<std::thread> t(16);
        {
            auto start = std::chrono::steady_clock::now();
            int it1 = 0, it2 = 0;
            for (int j = 0; j < 16; ++j) {
                

                int it3 = (vv[i].size() /16);
                if ((vv[i].size() % 16) > j) ++it3;

                int it4 = (vv[i + 4].size() / 16);
                if (vv[i + 4].size() % 16 > j) ++it4;

                t[j] = std::thread(uni_t, std::ref(vv[i]), std::ref(vv[i + 4]), it1, it2, it3, it4, std::ref(var[j]));
            }

            for (int j = 0; j < 16; ++j) {
               t[j].join();
            }

            for (auto& const elem : var) {               
                s += elem;                
            }

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> e_s = end - start;
            res_16t[i] = e_s;
            //std::cout << s << "\n";
        }       
    }

    std::cout << "Количество аппаратных ядер: " << tc << "\n\n\n";

    std::cout << "\t\t 1000 \t\t 10000 \t\t 100000 \t\t 1000000\n";
    std::cout << "1 поток: \t"<< res_1t[0].count()<<"s \t "<< res_1t[1].count() << "s \t " << res_1t[2].count() <<"s \t\t " << res_1t[3].count() << "s\n";
    std::cout << "2 потока:\t" << res_2t[0].count() << "s \t " << res_2t[1].count() << "s \t " << res_2t[2].count() << "s \t\t " << res_2t[3].count() << "s\n";
    std::cout << "4 потока:\t" << res_4t[0].count() << "s \t " << res_4t[1].count() << "s \t " << res_4t[2].count() << "s \t\t " << res_4t[3].count() << "s\n";
    std::cout << "8 потоков:      " << res_8t[0].count() << "s \t " << res_8t[1].count() << "s \t " << res_8t[2].count() << "s \t\t " << res_8t[3].count() << "s\n";
    std::cout << "16 потоков:     " << res_16t[0].count() << "s \t " << res_16t[1].count() << "s \t " << res_16t[2].count() << "s \t\t " << res_16t[3].count() << "s\n";


    return 0;
}


