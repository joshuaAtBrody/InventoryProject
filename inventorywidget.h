/*  Displays the items the player has in the inventory.
 *  Stores the inventory.
 *  By Joshua Brody 5/2024
 *
 */


#ifndef INVENTORYWIDGET_H
#define INVENTORYWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "itemsClass.h"
#include "itemslot.h"

namespace Ui {
class InventoryWidget;
}

class InventoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryWidget(QWidget *parent = nullptr);
    ~InventoryWidget();

private:
    Ui::InventoryWidget *ui;
    std::vector<ItemsClass*> itemsList;
    QMap<ItemEnumClass, ItemsClass*> itemsMap;
    int inventoryCount;



    void displayItemAtLocation(ItemsClass* item, int order);
    void resetDisplay();

    int findIndexInList(ItemsClass* item);

    ItemsClass* updateItemInList(ItemsClass* item);
    void replaceItemInList(ItemsClass* item);


public slots:
    void updateWithItem(ItemsClass* item);

    ///
    /// \brief setThisItemInView replace the current item type in the inventory with this item.
    ///     This will update the quantity.
    /// \param item the item to replace or add (if the item is not inventory)
    ///
    void setThisItemInView(ItemsClass* item);


signals:



};

#endif // INVENTORYWIDGET_H
