#include "handler.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication the_application(argc, argv);
    Handler the_handler;
    QTest::qExec(new TestFilter(),argc,argv);
    the_handler.show();
    return the_application.exec();
}
