#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class MsToCon : public LogCommand {    
public:    
    std::string mess;

    MsToCon() : LogCommand() {}

    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class MsToFile : public LogCommand {    
    std::ofstream file;
    std::string mess;
public:
    MsToFile() : LogCommand() {
        file.open("LogFile.txt", std::ios::app);        
    }   

    void print(const std::string& message) override {
        file << message << std::endl;
    }

    ~MsToFile() {
        file.close();
    }
};


void print(LogCommand& com) {
    std::string command;
    std::cout << "Enter text: ";
    std::getline(std::cin, command);
    com.print(command);
};


int main()
{

    MsToCon ms1;
    MsToFile ms2;    

    print(ms1);
    print(ms2);

    return 0;
}