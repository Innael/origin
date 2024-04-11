#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
#include <sstream>
#include <mutex>
#include <chrono>

int GetRandomNumber(int min, int max)
{    
    srand(time(NULL));        
    int num = min + rand() % (max - min + 1);
    return num;
}

std::mutex g_mut;

void calc(std::vector<std::string>& v, int cl, int& a) {
    int c = 0, it = 0, e = 0, er = 0;
    std::thread::id id = std::this_thread::get_id();
    std::ostringstream s;
    s << id;
    std::string s_id = s.str();
    v[1] = s_id;

    for (int i = 0; i < cl; ++i) {
        {
        std::lock_guard<std::mutex> grd(g_mut);        
        while (it < 10) {
            ++a;
            ++it;
            e = GetRandomNumber(1, 20+a);
            if (e == 17 || e > 500) {
                er = 5;
                a -= 2;
            }
        }
        it = 0;
        if (er == 5) {
            er = 0;
            v[i + 2] = "E";            
        }
        else v[i + 2] = "I";
    }
        Sleep(1500);
    }
    v[cl + 3] = "s";
}

void bar(std::vector<std::vector<std::string>>& vv, int tc, int cl) {    
    for (int f = 0; f < 5;) {
        {            
            std::lock_guard<std::mutex> grd(g_mut);
            std::system("cls");            
            std::cout << "# \t id \t Ход выполнения \t Время\n";
            for (int i = 0; i < tc; ++i) {
                std::cout << "Поток " << vv[i][0] << "  " << vv[i][1] << "\t";
                for (int j = 2; j < (cl + 2); ++j) {
                    std::cout << vv[i][j];
                }
                std::cout << "\t\t" << vv[i][cl + 2] << vv[i][cl + 3] << "\n\n";
                if (vv[i][cl + 2] != " ") {
                    f = 5;
                }
                else f = 0;
            }                         
        }
        Sleep(1000);
    }

}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int tc = 0, cl = 0, a =0;
    std::vector<std::vector<std::string>> vv;


    std::cout << "Введите количество потоков: ";
    std::cin >> tc;

    std::cout << "Введите длину расчётов: ";                  // вот только что это?
    std::cin >> cl;

    std::system("cls");

    std::vector<std::thread> t(tc);    

    for (int i = 0; i < tc; ++i) {
        {
            std::vector<std::string> v(cl + 4, " ");
            char n = ((i + 1) + '0');
            v[0] = n;                        
            vv.push_back(v);
        }
    }

    for (int i = 0; i < tc; ++i) {
        t[i] = std::thread(calc, std::ref(vv[i]), cl, std::ref(a));
    }
    std::thread b(bar, std::ref(vv), tc, cl);

    std::ostringstream st;
    std::string s_time;

    for (int i = 0; i < tc; ++i) {        
            auto start = std::chrono::steady_clock::now();
            t[i].join();
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> e_s = end - start;
            st << e_s.count();
            s_time = st.str();
            vv[i][cl + 2] = s_time;       
    }
    b.join();

    std::cout << "\n\nРезультат вычислений: " << a;

    return 0;
}


