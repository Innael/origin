#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram, int data_type);
    void SendDatagram(QByteArray data, int data_type);


private slots:
    void readPendingDatagrams(void);
    void readTextDatagrams(void);


private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* textUdpSocket;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendTextToGUI(QString data);

};

#endif // UDPWORKER_H
