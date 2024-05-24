#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public Text {
public:
    explicit Paragraph(Text* text) : text_(text) {}
    Text* text_;
    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public Text {
public:
    explicit Reversed(Text* text) : text_(text) {}
    Text* text_;
    void render(const std::string& data) const override {
        std::string rev_data = data;
        std::reverse(rev_data.begin(), rev_data.end());
        text_->render(rev_data);        
    }
};

class Link : public Text {
public:
    explicit Link(Text* text) : text_(text) {}
    Text* text_;
    void render(const std::string& adress, const std::string& data) const {
        std::cout << "<a href=";
        text_->render(adress);
        std::cout << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};


int main() {
    
    SetConsoleCP (1251);
    SetConsoleOutputCP(1251);
    
    auto text_block2 = new Paragraph(new Text());    
    text_block2->render("Paragrath text");
    std::cout << std::endl;

    auto text_block3 = new Reversed(new Text());    
    text_block3->render("А роза упала на лапу азора");
    std::cout << std::endl;

    auto text_block4 = new Link(new Text());
    text_block4->render("netology.ru", "Hello world");

    return 0;
}
