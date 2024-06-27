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



 public slots:
    void on_start();
    void send_time();

signals:

    void sig_time_send();

};

#endif // STOPWATCH_H
