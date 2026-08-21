/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_Serial;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Port;
    QComboBox *comboBox_Port;
    QPushButton *pushButton_Refresh;
    QLabel *label_Baud;
    QComboBox *comboBox_Baud;
    QPushButton *pushButton_Connect;
    QGroupBox *groupBox_Control;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_On;
    QPushButton *pushButton_Off;
    QPushButton *pushButton_Toggle;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Serial_Data;
    QPushButton *pushButton_Send;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(540, 460);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_Serial = new QGroupBox(centralwidget);
        groupBox_Serial->setObjectName("groupBox_Serial");
        horizontalLayout = new QHBoxLayout(groupBox_Serial);
        horizontalLayout->setObjectName("horizontalLayout");
        label_Port = new QLabel(groupBox_Serial);
        label_Port->setObjectName("label_Port");

        horizontalLayout->addWidget(label_Port);

        comboBox_Port = new QComboBox(groupBox_Serial);
        comboBox_Port->setObjectName("comboBox_Port");

        horizontalLayout->addWidget(comboBox_Port);

        pushButton_Refresh = new QPushButton(groupBox_Serial);
        pushButton_Refresh->setObjectName("pushButton_Refresh");

        horizontalLayout->addWidget(pushButton_Refresh);

        label_Baud = new QLabel(groupBox_Serial);
        label_Baud->setObjectName("label_Baud");

        horizontalLayout->addWidget(label_Baud);

        comboBox_Baud = new QComboBox(groupBox_Serial);
        comboBox_Baud->setObjectName("comboBox_Baud");

        horizontalLayout->addWidget(comboBox_Baud);

        pushButton_Connect = new QPushButton(groupBox_Serial);
        pushButton_Connect->setObjectName("pushButton_Connect");

        horizontalLayout->addWidget(pushButton_Connect);


        verticalLayout->addWidget(groupBox_Serial);

        groupBox_Control = new QGroupBox(centralwidget);
        groupBox_Control->setObjectName("groupBox_Control");
        horizontalLayout_2 = new QHBoxLayout(groupBox_Control);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_On = new QPushButton(groupBox_Control);
        pushButton_On->setObjectName("pushButton_On");

        horizontalLayout_2->addWidget(pushButton_On);

        pushButton_Off = new QPushButton(groupBox_Control);
        pushButton_Off->setObjectName("pushButton_Off");

        horizontalLayout_2->addWidget(pushButton_Off);

        pushButton_Toggle = new QPushButton(groupBox_Control);
        pushButton_Toggle->setObjectName("pushButton_Toggle");

        horizontalLayout_2->addWidget(pushButton_Toggle);


        verticalLayout->addWidget(groupBox_Control);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_Serial_Data = new QLineEdit(centralwidget);
        lineEdit_Serial_Data->setObjectName("lineEdit_Serial_Data");

        horizontalLayout_3->addWidget(lineEdit_Serial_Data);

        pushButton_Send = new QPushButton(centralwidget);
        pushButton_Send->setObjectName("pushButton_Send");

        horizontalLayout_3->addWidget(pushButton_Send);


        verticalLayout->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_Clear = new QPushButton(centralwidget);
        pushButton_Clear->setObjectName("pushButton_Clear");

        horizontalLayout_4->addWidget(pushButton_Clear);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt 6 Arduino Serial Controller", nullptr));
        groupBox_Serial->setTitle(QCoreApplication::translate("MainWindow", "Serial Port Configuration", nullptr));
        label_Port->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        pushButton_Refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_Baud->setText(QCoreApplication::translate("MainWindow", "Baud:", nullptr));
        pushButton_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_Control->setTitle(QCoreApplication::translate("MainWindow", "Quick Controls", nullptr));
        pushButton_On->setText(QCoreApplication::translate("MainWindow", "Turn ON LED", nullptr));
        pushButton_Off->setText(QCoreApplication::translate("MainWindow", "Turn OFF LED", nullptr));
        pushButton_Toggle->setText(QCoreApplication::translate("MainWindow", "Toggle LED", nullptr));
        lineEdit_Serial_Data->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter custom command (e.g. On, Off, Status)...", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("MainWindow", "Clear Console Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
