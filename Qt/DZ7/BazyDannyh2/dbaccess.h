#ifndef DBACCESS_H
#define DBACCESS_H

#include <QDialog>

namespace Ui {
class DBAccess;
}

class DBAccess : public QDialog
{
    Q_OBJECT

public:
    explicit DBAccess(QWidget *parent = nullptr);
    ~DBAccess();

signals:
   void sig_sendData(QVector<QString> dbData);


private slots:
   void on_buttonBox_accepted();

private:
    Ui::DBAccess *ui;
    QVector<QString> data;
};

#endif // DBACCESS_H
