#include <iostream>
#include <vector>
#include <string>

class big_intenger {
    std::vector<int> dt = {};    

public:
    explicit big_intenger(std::string ini) {
        int size = ini.length();
        for (int i = 0; i < size; ++i) {
            char b = ini[i];            
            int a = atoi(&b);            
            dt.push_back(a);
        }
    }

    big_intenger(big_intenger& const other) {
          this->dt = other.dt;
    }

    big_intenger(big_intenger&& other) noexcept {
        this->dt = move(other.dt);
    }

    big_intenger& operator = (big_intenger&& other) noexcept {
       std::vector<int> tm{};
       tm = std::move(this->dt);
       this->dt = std::move(other.dt);
       other.dt = std::move(tm);
       return *this;
    }

    big_intenger operator + (big_intenger other) {
        big_intenger temp("");
        std::vector<int> tvec{};
        int c = 0;
        int l1 = this->dt.size();
        int l2 = other.dt.size();
        int t1 = l1 - 1, t2 = l2 - 1;        

        if (l1 >= l2) {
            for (int i = 0; i < l2; ++i){                
                tvec.push_back((this->dt[t1] + other.dt[t2]+c) % 10);                
                c = ((this->dt[t1] + other.dt[t2] + c) / 10);                        
                --t1;
                --t2;
            }
            for (int i = -1; i < t1;) {
                tvec.push_back(this->dt[t1] + c);
                c = 0;
                --t1;
            }
        }
        else {
            for (int i = 0; i < l1; ++i) {
                tvec.push_back((this->dt[t1] + other.dt[t2] + c) % 10);
                c = ((this->dt[t1] + other.dt[t2] + c) / 10);
                --t1;
                --t2;
            }
            for (int i = -1; i < t2;) {
                tvec.push_back(other.dt[t2] + c);
                c = 0;
                --t2;
            }
        }
        if (c > 0) {
            tvec.push_back(c);
        }
        int l3 = tvec.size();
            for (int i = l3 - 1; i > -1; --i) {
            temp.dt.push_back(tvec[i]);
        }
        return temp;
    }

    big_intenger operator * (int other) {        
        big_intenger temp("");        
        for (int i = 0; i < other; ++i) {
            temp = temp + *this;                
        }
        return temp;
    }    

    big_intenger operator * (big_intenger other) {           // - вроде работает, но уже при уможениях, девятизначных чисел, на шестизначные, требуется несколько секунд
        big_intenger temp("");
        int l1 = other.dt.size() - 1;
        int c = other.dt[l1];
        int t = 1;
        while (l1 >= 0) {
            int c = other.dt[l1];
            for (int i = 0; i < c;) {
                --c;
                for (int j = 0; j < t; ++j) temp = temp + *this;
            }
            t *= 10;
            --l1;
        }
        
        return temp;
    }

    void print() {
        for (auto& const elem : dt) {
            std::cout << elem;
        }
    }
};

int main()
{
    big_intenger one("20000000");
    big_intenger two("500000");  
    big_intenger three = one + two;
    big_intenger four = std::move(one);
    three.print();
    std::cout << "\n";
    three = two * 30;
    three.print();
    std::cout << "\n";
    three = four * two;
    three.print();
    std::cout << "\n";
    four.print();
    
    return 0;
}

