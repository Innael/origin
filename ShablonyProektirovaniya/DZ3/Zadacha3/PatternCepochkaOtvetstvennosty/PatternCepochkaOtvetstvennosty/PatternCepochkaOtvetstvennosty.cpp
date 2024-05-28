#include <iostream>
#include <fstream>

class Type {    
public:
    std::string s_type = "Unknown";

    Type() {}

    Type(std::string& st) {
        s_type = st;
    }
};


class t_Warning : public Type {
public:
    t_Warning() {
        s_type = "Warning";
    }
};


class t_Error : public Type {
public:
    t_Error() {
        s_type = "Error";
    }
};


class t_FatalError : public Type {
public:
    t_FatalError() {
        s_type = "Fatal Error";
    }
};


class t_Unknown : public Type {
public:
    t_Unknown() {
        s_type = "Unknown";
    }
};



class LogMessage {
    Type _type;
    std::string _message;

public:

    LogMessage(Type& tp, std::string message) {
        _type = tp;
        _message = message;
    }   

    Type type() const {
        return _type;
    }
    const std::string& message() const {
        return _message;
    }
};


class Handler {
public:
    virtual void setNextHandler(Handler* handler) = 0;
    virtual void treatment(const LogMessage& lm) = 0;
};



class FatalErrorHandler : public Handler {
private:
    Handler* nextHandler = nullptr;
    
public:

    void setNextHandler(Handler* next) override {
        nextHandler = next;
    }
    void treatment(const LogMessage& lm) override {
        if (lm.type().s_type == "Fatal Error") {
            throw lm.message();
        }
        else if (nextHandler != nullptr) nextHandler->treatment(lm);
    }
};


class ErrorHandler : public Handler {
private:
    Handler* nextHandler = nullptr;
    std::ofstream file;

public:

    ErrorHandler(std::string file_name) : Handler() {
        file.open(file_name);
    }

    void setNextHandler(Handler* next) override {
        nextHandler = next;
    }
    void treatment(const LogMessage& lm) override {
        if (lm.type().s_type == "Error") {
            file << lm.message() << std::endl;
        }
        else if (nextHandler != nullptr) nextHandler->treatment(lm);
    }
    ~ErrorHandler() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class WarningHandler : public Handler {
private:
    Handler* nextHandler = nullptr;

public:

    void setNextHandler(Handler* next) override {
        nextHandler = next;
    }
    void treatment(const LogMessage& lm) override {
        if (lm.type().s_type == "Warning") {
            std::cout << lm.message() << std::endl;
        }
        else if (nextHandler != nullptr) nextHandler->treatment(lm);
    }
};

class UnknownErrorHandler : public Handler {
private:
    Handler* nextHandler = nullptr;                   // - вроде не нужно, но оставлено на всякий случай

public:

    void setNextHandler(Handler* next) override {            // - вроде не нужно, но оставлено на всякий случай
        nextHandler = next;
    }
    void treatment(const LogMessage& lm) override {
        if (lm.type().s_type == "Unknown") {
            throw std::string{ "An unknown error has occurred" };;
        }
        else if (nextHandler != nullptr) nextHandler->treatment(lm); // - вроде не нужно, но оставлено на всякий случай
    }
};


int main()
{
    
    t_FatalError fe1;
    t_Error e1;
    t_Warning w1;
    t_Unknown u1;

    LogMessage lm1(w1, "Don't do that");
    LogMessage lm2(e1, "Some kind of mistake");
    LogMessage lm3(u1, "Is there something wrong");
    LogMessage lm4(fe1, "Creepy Error");

    


    try {
        FatalErrorHandler fatal_error_handler;
        ErrorHandler error_handler("ErrorLog.txt");
        WarningHandler warning_handler;
        UnknownErrorHandler unknown_handler;

        fatal_error_handler.setNextHandler(&error_handler);
        error_handler.setNextHandler(&warning_handler);
        warning_handler.setNextHandler(&unknown_handler);

        fatal_error_handler.treatment(lm1);
        fatal_error_handler.treatment(lm2);
        fatal_error_handler.treatment(lm3);
        fatal_error_handler.treatment(lm4);

    }
    catch (std::string error_message)
    {
        std::cout << error_message << std::endl;
    }

    return 0;
}