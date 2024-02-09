#include <iostream>
#include <map>


int main()
{
    int a = 0;
    std::string t1 = "Kakoy Je Neudobny I Ne Gibkiy Okazalsya Konteyner map. No dlya dannoy zadachy, ne nashel nichego luchshe";
    std::cout << "[IN]: " << t1 <<"\n";    
    std::map<char, int> m1{};
    

    for (int i = 0; i < t1.length(); ++i) {          
        m1[t1[i]] += 1;
    };
    
    for (const auto& elem : m1) {
        if (a < elem.second) a = elem.second;
    }


    std::cout << "[Out]: \n";


    
        for (int i = a; i > 0; --i) {
            for (const auto& elem : m1) {
                if (elem.second == i) {
                    std::cout << elem.first << ": " << elem.second << std::endl;
                }
            }
        }  
        

    return 0;
}


