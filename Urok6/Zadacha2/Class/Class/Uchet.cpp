#include "Uchet.h"


Counter::Counter(int sch) {
        this->sch = sch;
    }

Counter::Counter() {
        sch = 1;
    }

    void Counter::UjeNeHochu() {
        ++sch;
    };

    void Counter::IschoHochu() {
        --sch;
    };

    int Counter::Naschitali() {
        return sch;
    };

