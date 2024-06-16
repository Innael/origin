#include <QCoreApplication>
#include <QSqlDatabase>
#include <QAuthenticator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase DB;
    QAuthenticator Aut_1;

    return a.exec();
}
