#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    ptrGraph = new QCPGraph(ui->cus_pl_wid->xAxis,ui->cus_pl_wid->yAxis);
    ui->cus_pl_wid->setInteraction(QCP::iRangeZoom, true);
    ui->cus_pl_wid->setInteraction(QCP::iRangeDrag, true);
}

Graph::~Graph()
{
    delete ui;
}

void Graph::start_paint()
{
    ui->cus_pl_wid->rescaleAxes();
    ui->cus_pl_wid->replot();
}

void Graph::start_clear()
{
    ptrGraph->data().clear();
    ui->cus_pl_wid->graph()->data()->clear();
    ui->cus_pl_wid->replot();
}
