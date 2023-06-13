/*#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>

namespace Ui {
class widget1;
}

class widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget1(QWidget *parent = nullptr);
    ~widget1();

private:
    Ui::widget1 *ui;
};

#endif // WIDGET1_H*/
#ifndef WIDGET1_H
#define WIDGET1_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QWidget>

namespace Ui {
class widget1;
}

class widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget1(QWidget *parent = nullptr);
    ~widget1();

private slots:
    void on_day_clicked();
    void recvWidget();

    void on_pushButton_clicked();

    void on_openj_clicked();

    void on_pushButton_3_clicked();

    void on_open_clicked();

    void on_pushButton_4_clicked();

signals:
    void showWidget();

private:
    Ui::widget1 *ui;
    double getData(double time);
    QSerialPort *serialPort;
};
#endif // WIDGET1_H
