#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

    QCPGraph* ptrGraph;
    void start_paint();
    void start_clear();

private:
    Ui::Graph *ui;    


};

#endif // GRAPH_H
