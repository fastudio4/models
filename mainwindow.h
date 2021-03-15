#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QMenuBar>
#include "modelctr.h"
#include "dataport.h"
#include "ui_mainwindow.h"

namespace MODEL {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actionAddPort();

    void actionAddDevice();

private:
    Ui::MainWindow ui;
    QTreeView *pTree;
    MODEL::ModelCTR *model;
    DATA::DataPort data;





};

} //namespace MODEL
#endif // MAINWINDOW_H
