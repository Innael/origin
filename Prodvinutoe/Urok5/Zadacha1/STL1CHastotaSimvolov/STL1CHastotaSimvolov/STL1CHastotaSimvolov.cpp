#include <iostream>
#include <map>


int main()
{
    int a = 0;
    std::string t1 = "Kakoy Je Neudobny I Ne Gibkiy Okazalsya Konteyner map";
    std::cout << "[IN]: " << t1 <<"\n";    
    std::map<char, int> m1{};
    

    for (int i = 0; i < t1.length(); ++i) {          
        m1[t1[i]] += 1;
    };
    

    std::cout << "[Out]: \n";


    if (t1.length() < 256) {     // - На случай, очень длинных строк
        a = t1.length();
    }
    else a = 256;
        for (int i = a; i > 0; --i) {
            for (const auto& elem : m1) {
                if (elem.second == i) {
                    std::cout << elem.first << ": " << elem.second << std::endl;
                }
            }
        }
    
    

    return 0;
}


