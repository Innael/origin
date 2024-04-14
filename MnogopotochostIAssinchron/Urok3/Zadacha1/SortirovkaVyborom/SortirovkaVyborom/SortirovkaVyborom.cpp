#include <iostream>
#include <thread>
#include <future>
#include <vector>


void s_min(std::vector<int>& v, int n, std::promise<int> prom) {
    int temp = v[n], nu = n;
    for (int i = n; i < v.size(); ++i) {
        if (temp > v[i]) {
            temp = v[i];
            nu = i;
        }
    }
    prom.set_value(nu);
}


int main()
{
    int t = 0, nu = 0;
    std::vector<int> v{ 5, 4, 3, 2, 1, 10, 8, 9, 7, 6, 5, 21, 22, 24, 27, 30, 15, 14, 13, 12, 11 };

    for (int i = 0; i < v.size(); ++i) {        
        std::promise<int> prom;
        std::future<int> ft_res = prom.get_future();
        auto ft = std::async(s_min, std::ref(v), i, std::move(prom));
        nu = ft_res.get();        
        t = v[i];
        v[i] = v[nu];
        v[nu] = t;
    }

    for (auto& const elem : v) {
        std::cout << elem << ' ';
    }

    return 0;
}
