#include "calculator.h"
#include <QMediaPlayer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    return a.exec();
}
