#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>
namespace MODEL {

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
    virtual ~Application();
};

} //namespace MODEL
#endif // APPLICATION_H
