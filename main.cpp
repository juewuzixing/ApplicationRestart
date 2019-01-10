#include <QApplication>
#include <QProcess>
#include <QDir>

#include "widget.hpp"

int main(int argc, char *argv[])
{
    // 事件循环机制重启
    int nExitCode = 0;
    do {
        QApplication a(argc, argv);

        Widget w;
        w.show();
        nExitCode = a.exec();
    } while (nExitCode == Widget::EXIT_CODE_REBOOT);

    return nExitCode;

    // 进程控制机制重启
//    QApplication a(argc, argv);

//    Widget w;
//    w.show();

//    return a.exec();
}
