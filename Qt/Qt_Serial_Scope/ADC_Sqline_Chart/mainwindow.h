#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <QtCharts>
#include <QSerialPort>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void Data();

private:
    Ui::MainWindow *ui;
    QSerialPort* COMPORT;

    QChart* chart;
    QSplineSeries* series;
    QChartView* chartview;
    QValueAxis* axisX;
    QValueAxis* axisY;
    double timeStep = 0.0;
};
#endif // MAINWINDOW_H
