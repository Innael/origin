#include <iostream>
#include <future>
#include <vector>




void multiply3(int& a) {
    a *= 3;    
}

template <class Iterator, class Func>                           
void parr_for_each(Iterator first, Iterator second, Func f) { 
    auto as = std::distance(first, second);
    if (as == 1) {
        f(*first);      
    }    
    else if (as > 2 ) {
        auto mid = first;
        std::advance(mid, as / 2);        
        auto ft1 = std::async(std::launch::deferred, parr_for_each<Iterator, Func>, first, mid, f);       
        auto ft2 = std::async(std::launch::deferred, parr_for_each<Iterator, Func>, mid, second, f);
        ft1.get();
        ft2.get();
    }
    else if (as == 2) {
        auto mid = first;
        std::advance(mid, 1);
        f(*first);
        f(*mid);        
    }
}


int main()
{

    std::vector<int> v{ 10, 20, 30, 40, 50, 1, 2, 3, 4, 5, 60, 70, 80, 90, 100 };

    parr_for_each(v.begin(), v.end(), multiply3);
    for (auto& const elem : v) {
        std::cout << elem << ' ';
    }

    return 0;
}


