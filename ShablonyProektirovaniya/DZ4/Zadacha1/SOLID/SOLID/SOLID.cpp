#include <iostream>
#include <fstream>


class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string print()  = 0;   
};


class Text_Data : public Printable {
private:
    std::string data_;   
public:
    Text_Data(std::string data) {
        data_ = data;
    }
     std::string print() override {
        return data_;
    }
};


class HTML_Data : public Printable {
private:
    std::string data_;
public:
    HTML_Data(std::string data) {
        data_ = data;
    }
    std::string print() override {
        return "<html>" + data_ + "<html/>";
    }
};


class JSON_Data : public Printable {
private:
    std::string data_;
public:
    JSON_Data(std::string data) {
        data_ = data;
    }
    std::string print() override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, Printable& printable)
{    
        file << printable.print();       
}


int main()
{
    Text_Data text("Some text");
    HTML_Data h_text("HTML Text");
    JSON_Data j_text("JSON Text");
    std::ofstream file;
    std::ofstream file2;
    std::ofstream file3;
    file.open("TextFile.txt");
    file2.open("HTMLFile.txt");
    file3.open("JSONFile.txt");


    if (file.is_open()) {
        saveTo(file, text);
    }

    if (file2.is_open()) {
        saveTo(file2, h_text);
    }

    if (file3.is_open()) {
        saveTo(file3, j_text);
    }

    file.close();
    file2.close();
    file3.close();
    return 0;
}

