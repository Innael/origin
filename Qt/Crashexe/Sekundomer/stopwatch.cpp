#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject {parent}
{
   QTimer *qtm = new QTimer(this);
   connect(qtm, &QTimer::timeout, this, &Stopwatch::send_time);
}

void Stopwatch::on_start()
{
   qtm->start(100);
}


void Stopwatch::send_time()
{
   emit sig_time_send();
}



Stopwatch::~Stopwatch(){

}
