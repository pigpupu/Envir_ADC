#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStringList serialNamePort;

    ui->setupUi(this);
    this->setWindowTitle("envir_adc");

    /* 创建一个串口对象 */
    serialPort = new QSerialPort(this);

    /* 搜索所有可用串口 */
    foreach (const QSerialPortInfo &inf0, QSerialPortInfo::availablePorts()) {
    serialNamePort<<inf0.portName();
     }
    ui->serialBox->addItems(serialNamePort);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_day_clicked()
{
    this->hide();
    emit showWidget1();
}

void Widget::recvW1()
{
    this->show();
}

void Widget::on_night_clicked()
{
    this->hide();
    emit showWidget2();
}


void Widget::recvW2()
{
    this->show();
}


void Widget::on_close_clicked()
{
    serialPort->close();
}


void Widget::on_pushButton_2_clicked()
{
    /* 串口设置 */
    serialPort->setPortName(ui->serialBox->currentText());
    serialPort->setBaudRate(ui->baudrateBox->currentText().toInt());
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setParity(QSerialPort::NoParity);

    /* 打开串口提示框 */
    if (true == serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "提示", "串口打开成功");
    }
    else
    {
        QMessageBox::critical(this, "提示", "串口打开失败");
    }
}




