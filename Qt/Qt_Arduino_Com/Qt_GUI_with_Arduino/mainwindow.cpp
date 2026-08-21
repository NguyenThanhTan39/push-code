#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // const auto serialPortInfos = QSerialPortInfo::availablePorts();
    // for (const QSerialPortInfo &portInfo : serialPortInfos) {
    //     qDebug() << "---";
    //     qDebug() << "Port Name      :" << portInfo.portName();       // Tên dùng cho setPortName()
    //     qDebug() << "System Location:" << portInfo.systemLocation();   // Đường dẫn /dev/...
    // }

    COMPORT = new QSerialPort();
    COMPORT->setPortName("cu.usbmodemFX2348N1");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QIODevice::ReadWrite);

    if(COMPORT->isOpen())
    {
        qDebug() << "Serial Port is connected.";
    }
    else
    {
        qDebug() << "Serial Port is not connected.";
    }
    connect(COMPORT, &QSerialPort::readyRead, this, &MainWindow::Read_Data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Send_clicked()
{
    if (COMPORT->isOpen())
    {
        COMPORT->write(ui->lineEdit_Serial_Data->text().toUtf8() + char(10));
        COMPORT->flush();
    }
}

void MainWindow::Read_Data()
{
    if (COMPORT->isOpen())
    {
        while (COMPORT->bytesAvailable())
        {
            Data_From_SerialPort += COMPORT->readAll();
        }
        if (Data_From_SerialPort.at(Data_From_SerialPort.length()-1) == '\n')
        {
            Is_Data_Received = true;
        }

        if (Is_Data_Received)
        {
            Is_Data_Received = false;
            ui->textEdit->append(Data_From_SerialPort);
            Data_From_SerialPort = "";
        }
    }
}
