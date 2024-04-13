#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
#include <sstream>
#include <mutex>
#include <chrono>


class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

consol_parameter cp;


int GetRandomNumber(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

std::mutex g_mut;

void calc(std::vector<std::string>& v, int cl, int& a, int n) {
    int c = 0, it = 0, e = 0, er = 0;
    std::thread::id id = std::this_thread::get_id();
    std::ostringstream s;
    s << id;
    std::string s_id = s.str();
    v[1] = s_id;

    {
        std::lock_guard<std::mutex> grd(g_mut);
        cp.SetPosition(0, n + 1);
        std::cout << "Поток " << v[0] << "  " << v[1] << "\t";
    }

    for (int i = 0; i < cl; ++i) {
        {
            std::lock_guard<std::mutex> grd(g_mut);     
            while (it < 10) {
                ++a;
                ++it;                       
                e = GetRandomNumber(1, 20 + a);
                if (e == 17 || e > 500) {
                    er = 5;
                    a -= 2;
                }
            }
            it = 0;
            if (er == 5) {
                er = 0;
                v[i + 2] = "I";
                cp.SetPosition(i + 17, n + 1);
                cp.SetColor(4, 0);
                std::cout << v[i + 2];
                cp.SetColor(15, 0);
            }
            else {
                v[i + 2] = "I";
                cp.SetPosition(i + 17, n + 1);
                std::cout << v[i + 2];
            }
        }
        Sleep(1500);
    }
    v[cl + 3] = "s";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int tc = 0, cl = 0, a = 0;
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
        t[i] = std::thread(calc, std::ref(vv[i]), cl, std::ref(a), i);
    }    

    std::ostringstream st;
    std::string s_time;
    std::cout << "# \t id \t Ход выполнения \t Время\n";

    for (int i = 0; i < tc; ++i) {        
        auto start = std::chrono::steady_clock::now();
        t[i].join();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> e_s = end - start;
        st << e_s.count();
        s_time = st.str();
        vv[i][cl + 2] = s_time;
    }

    for (int i = 0; i < tc; ++i) {
        cp.SetPosition(cl + 30, i + 1);
        std::cout << vv[i][cl + 2] << vv[i][cl + 3];
    }    

    cp.SetPosition(0, tc + 3);
    std::cout << "\n\nРезультат вычислений: " << a;

    return 0;
}
