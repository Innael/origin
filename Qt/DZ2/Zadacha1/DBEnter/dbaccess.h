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

private:
    Ui::DBAccess *ui;
};

#endif // DBACCESS_H
