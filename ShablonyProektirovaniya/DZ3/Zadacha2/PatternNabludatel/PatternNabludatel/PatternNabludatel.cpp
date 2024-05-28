#include <iostream>
#include <fstream>
#include <vector>


class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};


class WrittenBag {

    std::vector<std::weak_ptr<Observer>> observers;

public:

    void warning(const std::string& message) const {        
        for (auto& elem : observers) {
            if (elem.lock() != NULL) {
                elem.lock()->onWarning(message);
            }            
        }
    }

    void error(const std::string& message) const {
        for (auto& elem : observers) {
            if (elem.lock() != NULL) {
                elem.lock()->onError(message);
            }
        }
    }

    void fatalError(const std::string& message) const {
        for (auto& elem : observers) {
            if (elem.lock() != NULL) {
                elem.lock()->onFatalError(message);
            }
        }
    }

    void AddObs(std::shared_ptr<Observer> obs) {
        if (obs != NULL) {
            std::weak_ptr<Observer> ptr = obs;
            observers.push_back(obs);
        }
    }

    void RemoveObs(std::shared_ptr<Observer> obs) {
        for (auto& elem : observers) {
            if (obs != NULL) {                
                //auto it = std::remove(observers.begin(), observers.end(), ptr.lock());   // - выдаёт ошибку C2676 
                //observers.erase(it, observers.end());
            }
        }
    }
};


class WarnObs : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class ErrObs : public Observer {
    std::ofstream file;
public:
    ErrObs() : Observer() {
        file.open("ErrorLog.txt");
    }
    void onError(const std::string& message) override{
        if (file.is_open()) {
            file << message << std::endl;
        }
    }
    ~ErrObs() {
        if (file.is_open()) {
            file.close();
        }
    }
};


class FatalErrObs : public Observer {
    std::ofstream file;
public:
    FatalErrObs() : Observer() {
        file.open("FatalErrorLog.txt");
    }
    void onFatalError(const std::string& message) override {
        if (file.is_open()) {
            file << message << std::endl;
        }
        std::cout << message << std::endl;
    }
    ~FatalErrObs() {
        if (file.is_open()) {
            file.close();
        }
    }
};


int main()
{
    WrittenBag wb1;
    {
        auto wob1 = std::make_shared<WarnObs>();
        auto wob2 = std::make_shared<WarnObs>();
        auto err_obs1 = std::make_shared<ErrObs>();
        auto err_obs2 = std::make_shared<ErrObs>();
        auto f_err = std::make_shared<FatalErrObs>();

        wb1.AddObs(wob1);
        wb1.AddObs(wob2);
        wb1.AddObs(err_obs1);
        wb1.AddObs(err_obs2);
        wb1.AddObs(f_err);

        wb1.RemoveObs(wob2);  // - стандартный метод удаление из вектора, в случае, со слабым указателем приводит к ошибке C2676

        wb1.warning("Warning detected!");
        wb1.error("Error detected!");
        wb1.fatalError("Fatal Error detected!");

    }
    auto wob3 = std::make_shared<WarnObs>();
    wb1.AddObs(wob3);

    wb1.warning("Warning2 detected!");
    wb1.error("Error2 detected!");
    wb1.fatalError("Fatal Error2 detected!");

    return 0;
}
