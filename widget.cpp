#include <QMessageBox>
#include <QPushButton>
#include <QProcess>
#include <QDir>

#include "ui_widget.h"
#include "widget.hpp"

int const Widget::EXIT_CODE_REBOOT = -123456789;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *pButtonEvent = new QPushButton(this);
    pButtonEvent->setText(QStringLiteral("事件循环机制重启"));
    pButtonEvent->setGeometry(100,100,200,30);

    QPushButton *pButtonProcess = new QPushButton(this);
    pButtonProcess->setText(QStringLiteral("进程控制机制重启"));
    pButtonProcess->setGeometry(100,140,200,30);

    connect(pButtonEvent,SIGNAL(clicked(bool)),this,SLOT(eventReboot()));
    connect(pButtonProcess,SIGNAL(clicked(bool)),this,SLOT(processReboot()));
}
Widget::~Widget()
{
    delete ui;
}

void Widget::eventReboot() {
    qApp->exit(Widget::EXIT_CODE_REBOOT);
}

void Widget::processReboot() {
    QString program = QApplication::applicationFilePath();
    QStringList arg = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program,arg,workingDirectory);
    QApplication::exit();
}
