/********************************************************************************
** Form generated from reading UI file 'itemslot.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMSLOT_H
#define UI_ITEMSLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemSlot
{
public:
    QLabel *itemImageLabel;
    QLabel *itemNameLabel;

    void setupUi(QWidget *ItemSlot)
    {
        if (ItemSlot->objectName().isEmpty())
            ItemSlot->setObjectName("ItemSlot");
        ItemSlot->resize(130, 150);
        itemImageLabel = new QLabel(ItemSlot);
        itemImageLabel->setObjectName("itemImageLabel");
        itemImageLabel->setGeometry(QRect(0, 0, 128, 128));
        itemImageLabel->setAlignment(Qt::AlignCenter);
        itemImageLabel->setWordWrap(true);
        itemNameLabel = new QLabel(ItemSlot);
        itemNameLabel->setObjectName("itemNameLabel");
        itemNameLabel->setGeometry(QRect(0, 129, 130, 21));
        itemNameLabel->setAlignment(Qt::AlignCenter);
        itemNameLabel->setWordWrap(true);

        retranslateUi(ItemSlot);

        QMetaObject::connectSlotsByName(ItemSlot);
    } // setupUi

    void retranslateUi(QWidget *ItemSlot)
    {
        ItemSlot->setWindowTitle(QCoreApplication::translate("ItemSlot", "Form", nullptr));
        itemImageLabel->setText(QCoreApplication::translate("ItemSlot", "Image Label", nullptr));
        itemNameLabel->setText(QCoreApplication::translate("ItemSlot", "Item Label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemSlot: public Ui_ItemSlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMSLOT_H
