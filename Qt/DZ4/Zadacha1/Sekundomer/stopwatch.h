#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>

#include <QObject>

class Stopwatch: public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~ Stopwatch();
    QTimer *qtm;
    double time_pass;
    bool time_on;
    int circle_number;
    double c_time1;
    double c_time2;
    double res_time;
    double best_time;

    void on_start();
    void circle_res();
    void reset();

 public slots:
    void send_time();

signals:

    void sig_time_send(double time_pass);
    void sig_send_res(int circle_number, double res_time, double best_time);
    void sig_reset();
};

#endif // STOPWATCH_H
