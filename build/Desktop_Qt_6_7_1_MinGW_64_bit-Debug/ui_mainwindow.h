/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <inventorywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    InventoryWidget *invWig;
    QPushButton *mineButton;
    QPushButton *dumpButton;
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *ethyleneTarget;
    QCheckBox *bauxiteTarget;
    QCheckBox *peridotTarget;
    QCheckBox *hydrogenTarget;
    QCheckBox *sulphurTarget;
    QCheckBox *methaneTarget;
    QCheckBox *ironTarget0;
    QCheckBox *bariumOTarget;
    QCheckBox *goldTarget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        invWig = new InventoryWidget(centralwidget);
        invWig->setObjectName("invWig");
        invWig->setGeometry(QRect(30, 560, 1200, 300));
        mineButton = new QPushButton(centralwidget);
        mineButton->setObjectName("mineButton");
        mineButton->setGeometry(QRect(30, 40, 200, 51));
        dumpButton = new QPushButton(centralwidget);
        dumpButton->setObjectName("dumpButton");
        dumpButton->setGeometry(QRect(30, 130, 150, 51));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 90, 200, 23));
        progressBar->setValue(24);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(840, 10, 160, 292));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ethyleneTarget = new QCheckBox(layoutWidget);
        ethyleneTarget->setObjectName("ethyleneTarget");

        verticalLayout->addWidget(ethyleneTarget);

        bauxiteTarget = new QCheckBox(layoutWidget);
        bauxiteTarget->setObjectName("bauxiteTarget");

        verticalLayout->addWidget(bauxiteTarget);

        peridotTarget = new QCheckBox(layoutWidget);
        peridotTarget->setObjectName("peridotTarget");

        verticalLayout->addWidget(peridotTarget);

        hydrogenTarget = new QCheckBox(layoutWidget);
        hydrogenTarget->setObjectName("hydrogenTarget");

        verticalLayout->addWidget(hydrogenTarget);

        sulphurTarget = new QCheckBox(layoutWidget);
        sulphurTarget->setObjectName("sulphurTarget");

        verticalLayout->addWidget(sulphurTarget);

        methaneTarget = new QCheckBox(layoutWidget);
        methaneTarget->setObjectName("methaneTarget");

        verticalLayout->addWidget(methaneTarget);

        ironTarget0 = new QCheckBox(layoutWidget);
        ironTarget0->setObjectName("ironTarget0");

        verticalLayout->addWidget(ironTarget0);

        bariumOTarget = new QCheckBox(layoutWidget);
        bariumOTarget->setObjectName("bariumOTarget");

        verticalLayout->addWidget(bariumOTarget);

        goldTarget = new QCheckBox(layoutWidget);
        goldTarget->setObjectName("goldTarget");

        verticalLayout->addWidget(goldTarget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mineButton->setText(QCoreApplication::translate("MainWindow", "Mine", nullptr));
        dumpButton->setText(QCoreApplication::translate("MainWindow", "Dump", nullptr));
        ethyleneTarget->setText(QCoreApplication::translate("MainWindow", "Ethylene Gas Cloud", nullptr));
        bauxiteTarget->setText(QCoreApplication::translate("MainWindow", "Bauxite", nullptr));
        peridotTarget->setText(QCoreApplication::translate("MainWindow", "Peridot Gems", nullptr));
        hydrogenTarget->setText(QCoreApplication::translate("MainWindow", "Hydrogen Cloud", nullptr));
        sulphurTarget->setText(QCoreApplication::translate("MainWindow", "Sulphur", nullptr));
        methaneTarget->setText(QCoreApplication::translate("MainWindow", "Methane Gas Cloud", nullptr));
        ironTarget0->setText(QCoreApplication::translate("MainWindow", "Iron", nullptr));
        bariumOTarget->setText(QCoreApplication::translate("MainWindow", "Barium O", nullptr));
        goldTarget->setText(QCoreApplication::translate("MainWindow", "Gold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
