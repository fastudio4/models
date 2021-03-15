#include "mainwindow.h"
#include "application.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    MODEL::Application a(argc, argv);
    MODEL::MainWindow w;
    w.show();
    return a.exec();
}
