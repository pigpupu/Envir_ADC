#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class widget2;
}

class widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit widget2(QWidget *parent = nullptr);
    ~widget2();


private slots:
    void on_night_clicked();
    void recvWidget();

    void on_pushButton_clicked();

    void on_openj_clicked();

    void on_pushButton_3_clicked();

    void on_open_clicked();

    void on_pushButton_4_clicked();

signals:
    void showWidget();

private:
    Ui::widget2 *ui;
    QSerialPort *serialPort;
};

#endif // WIDGET2_H
