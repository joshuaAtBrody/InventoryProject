/********************************************************************************
** Form generated from reading UI file 'inventorywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYWIDGET_H
#define UI_INVENTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryWidget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QProgressBar *InventoryFullnessBar;

    void setupUi(QWidget *InventoryWidget)
    {
        if (InventoryWidget->objectName().isEmpty())
            InventoryWidget->setObjectName("InventoryWidget");
        InventoryWidget->resize(1200, 250);
        InventoryWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 71, 71);"));
        scrollArea = new QScrollArea(InventoryWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 25, 1200, 300));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1198, 298));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1201, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        InventoryFullnessBar = new QProgressBar(InventoryWidget);
        InventoryFullnessBar->setObjectName("InventoryFullnessBar");
        InventoryFullnessBar->setGeometry(QRect(884, 0, 311, 28));
        InventoryFullnessBar->setValue(0);

        retranslateUi(InventoryWidget);

        QMetaObject::connectSlotsByName(InventoryWidget);
    } // setupUi

    void retranslateUi(QWidget *InventoryWidget)
    {
        InventoryWidget->setWindowTitle(QCoreApplication::translate("InventoryWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryWidget: public Ui_InventoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYWIDGET_H
