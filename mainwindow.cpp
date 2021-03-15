#include "mainwindow.h"
#include "dialogdevice.h"
#include "dialogport.h"

namespace MODEL {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle(tr("ModBus RTU Scaner"));
    pTree = new QTreeView(this);
    model = new MODEL::ModelCTR(this);
    pTree->setModel(model);
    setCentralWidget(pTree);
    connect(ui.actionAdd_port, SIGNAL(triggered()), this, SLOT(actionAddPort()));
    connect(ui.actionAdd_device, SIGNAL(triggered()), this, SLOT(actionAddDevice()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::actionAddPort()
{
    MODEL::DialogPort Dia(this);
    Dia.exec();
}

void MainWindow::actionAddDevice()
{
    MODEL::DialogDevice Dia(this);
    Dia.exec();

}

} //namespace MODEL
