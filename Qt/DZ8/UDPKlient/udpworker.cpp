#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    textUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    textUdpSocket->bind(QHostAddress::LocalHost, 12347);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);
    connect(textUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readTextDatagrams);
}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram, int data_type)
{
   if (data_type == 1){
    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;

    emit sig_sendTimeToGUI(dateTime);
   }
   else{
       QByteArray text_data;
       text_data = datagram.data();

       QDataStream textStr(&text_data, QIODevice::ReadOnly);
       QString dataText;
       textStr >> dataText;
       if (dataText == "") dataText = "пустое до не приличия( возможно это начало DoS-атаки, на ваш компьютер или же, отправитель, просто забыл, ввести данные),";
       QString completeDataText = "Принято сообщение:\n" + dataText + "\nот " + datagram.senderAddress().toString() + ", размер сообщения(байт): " + QString::number(data_type);
       emit sig_sendTextToGUI(completeDataText);
   }
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data, int data_type)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    if (data_type == 1) serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
    else textUdpSocket->writeDatagram(data, QHostAddress::LocalHost, 12347);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram, 1);
    }

}

void UDPworker::readTextDatagrams( void )
{
    while(textUdpSocket->hasPendingDatagrams()){
            int mes_size = textUdpSocket->pendingDatagramSize();
            QNetworkDatagram datagram = textUdpSocket->receiveDatagram();
            ReadDatagram(datagram, mes_size);  // - понимаю, что так, совмещать 2 аргумента, пихая их в один, конечно не стоит, но в данном конкретном случае, проблем быть не должно
    }

}
