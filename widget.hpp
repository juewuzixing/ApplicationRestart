#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    static int const EXIT_CODE_REBOOT;

public slots:
    void eventReboot();
    void processReboot();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_HPP
