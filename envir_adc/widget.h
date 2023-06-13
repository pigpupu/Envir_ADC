#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_day_clicked();

    void on_night_clicked();

    void recvW1();

    void recvW2();

    void on_close_clicked();

    void on_pushButton_2_clicked();

signals:
    void showWidget1();
    void showWidget2();
private:
    Ui::Widget *ui;
    QSerialPort *serialPort;
};
#endif // WIDGET_H
