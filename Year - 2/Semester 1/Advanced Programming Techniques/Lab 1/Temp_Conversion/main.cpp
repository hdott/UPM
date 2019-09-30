#include "tempconversion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TempConversion w;
    w.show();

    return a.exec();
}
