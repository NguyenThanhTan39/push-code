#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    series = new QSplineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Do thi dien ap ADC0 Arduino");
    chart->setVisible(true);

    axisX = new QValueAxis();
    axisX->setRange(0, 10.0);
    axisX->setTitleText("Time (s)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(-1.0, 6.0);
    axisY->setTitleText("Voltage (V)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartview);
    chartview->setVisible(true);

    COMPORT = new QSerialPort();
    COMPORT->setPortName("cu.usbmodemFX2348N1");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QIODevice::ReadOnly);

    if (COMPORT->isOpen())
    {
        qDebug() << "Serial connected!";
        connect(COMPORT, &QSerialPort::readyRead, this, &MainWindow::Data);
    }
    else
    {
        qDebug() << "Serial Error: " << COMPORT->errorString();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Data()
{
    while(COMPORT->canReadLine())
    {
        QByteArray data = COMPORT->readLine();
        QString StrData = QString::fromUtf8(data).trimmed();
        bool ok;
        double voltage = StrData.toDouble(&ok);
        if (ok)
        {
            series->append(timeStep, voltage);

            if (timeStep > 10.0)
            {
                axisX->setRange(timeStep - 10.0, timeStep);
            }

            if (series->count() > 300) series->remove(0);

            timeStep += 0.05;
        }
    }
}
