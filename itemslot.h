/* This class will hold the items name and image. And will be shown in the inventory widget.
 *  By Joshua Brody 5/2024
 */

#ifndef ITEMSLOT_H
#define ITEMSLOT_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class ItemSlot;
}

class ItemSlot : public QWidget
{
    Q_OBJECT

public:
    explicit ItemSlot(QWidget *parent = nullptr);

    ~ItemSlot();

    void stuffSlot(QString itemName, QString itemImagePath);

private:
    Ui::ItemSlot *ui;

    QString varItemName;
    QString varItemImagePath;


public slots: // Inputing


signals:    // Outputing

};

#endif // ITEMSLOT_H
