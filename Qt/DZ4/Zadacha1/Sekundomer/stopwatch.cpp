#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject {parent}
{
   qtm = new QTimer(this);
   connect(qtm, &QTimer::timeout, this, &Stopwatch::send_time);
   time_pass = 0;
   time_on = false;
   circle_number = 0;
   c_time1 = 0;
   c_time2 = 0;
   res_time = 0;
   best_time = 99999;
}

void Stopwatch::on_start()
{
   if (time_on == false){
       time_on = true;
       qtm->start(100);
   } else
   {
       time_on = false;
       qtm->stop();
   }
}


void Stopwatch::send_time()
{
   time_pass += 0.1;
   emit sig_time_send(time_pass);
}

void Stopwatch::circle_res()
{
   ++circle_number;
   c_time2 = time_pass;
   res_time = c_time2 - c_time1;
   if (res_time < best_time) best_time = res_time;
   emit sig_send_res(circle_number, res_time, best_time);
   c_time1 = c_time2;
}

void Stopwatch::reset()
{
    time_pass = 0;
    circle_number = 0;
    c_time1 = 0;
    c_time2 = 0;
    res_time =0;
    best_time = 99999;
    emit sig_reset();
}

bool Stopwatch::check_time_on()
{
    return time_on;
}

Stopwatch::~Stopwatch(){

}
