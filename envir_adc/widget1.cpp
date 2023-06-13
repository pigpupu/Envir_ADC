/*#include "widget1.h"
#include "ui_widget1.h"

widget1::widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget1)
{
    ui->setupUi(this);
}

widget1::~widget1()
{
    delete ui;
}*/
#include "widget1.h"
#include "ui_widget1.h"
#include "widget.h"
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

widget1::widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget1)
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

widget1::~widget1()
{
    delete ui;
}

void widget1::on_day_clicked()
{
    this->hide();
    emit showWidget();
}

void widget1::recvWidget()
{
    this->show(); //显示本界面
}


void widget1::on_pushButton_clicked()
{
    this->hide();
    emit showWidget();
}

void widget1::on_openj_clicked()
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


void widget1::on_pushButton_3_clicked()
{
     serialPort->close();
}

//QString a="1";
void widget1::on_open_clicked()
{
    QByteArray array1;
    array1.resize(2);
    array1[0] = 0x0;
    array1[1] = 0x0;
    serialPort->write(array1);
    /*int num = a.toInt();
    a = a.setNum(num,16);
    ui->lineEdit->clear();
    ui->lineEdit->setText(a);
    serialPort->write(ui->lineEdit->text().toLatin1());*/
}

//QString b="0";
void widget1::on_pushButton_4_clicked()
{
    QByteArray array1;
    array1.resize(2);
    array1[0] = 0x1;
    array1[1] = 0x1;
    serialPort->write(array1);
    /*int num1 = b.toInt();
    b = b.setNum(num1,16);
    ui->lineEdit->clear();
    ui->lineEdit->setText(b);
    serialPort->write(ui->lineEdit->text().toLatin1());*/
}

