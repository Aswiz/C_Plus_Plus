/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *block_3;
    QPushButton *pushButton_1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *block_2;
    QPushButton *block_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1063, 569);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        block_3 = new QPushButton(centralWidget);
        block_3->setObjectName(QStringLiteral("block_3"));
        block_3->setGeometry(QRect(10, 400, 211, 51));
        block_3->setStyleSheet(QLatin1String("	background-color: #CD3116;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(960, 400, 51, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 80, 31, 371));
        label->setStyleSheet(QLatin1String("	background-color: #B64500;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;\n"
"   	border-radius: 10px;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 80, 31, 371));
        label_2->setStyleSheet(QLatin1String("	background-color: #B64500;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;\n"
"   	border-radius: 10px;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(650, 80, 31, 371));
        label_3->setStyleSheet(QLatin1String("	background-color: #B64500;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;\n"
"   	border-radius: 10px;"));
        block_2 = new QPushButton(centralWidget);
        block_2->setObjectName(QStringLiteral("block_2"));
        block_2->setGeometry(QRect(30, 350, 171, 51));
        block_2->setStyleSheet(QLatin1String("	background-color: #CD3116;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;"));
        block_1 = new QPushButton(centralWidget);
        block_1->setObjectName(QStringLiteral("block_1"));
        block_1->setGeometry(QRect(50, 300, 131, 51));
        block_1->setStyleSheet(QLatin1String("	background-color: #CD3116;\n"
"	color: white; \n"
"	border: 1px solid gray;\n"
"	position: relative;\n"
"	height: 100%;\n"
"	width: 100%;\n"
"	margin-right: -1.9%;\n"
"    font: 400 20px Numbers;\n"
"	color:#FFFFFF;"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(910, 450, 51, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(960, 450, 51, 51));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1010, 450, 51, 51));
        MainWindow->setCentralWidget(centralWidget);
        label_3->raise();
        label_2->raise();
        label->raise();
        block_3->raise();
        pushButton_1->raise();
        block_2->raise();
        block_1->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1063, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        block_3->setText(QString());
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        block_2->setText(QString());
        block_1->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
