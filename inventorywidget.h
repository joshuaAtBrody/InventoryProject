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
    QMap<ItemEnumClass, ItemsClass*> itemsMap;
    std::vector<ItemEnumClass> itemsOrder;
    int inventoryCount;


    ///
    /// \brief displayItemAtLocation create labels for the item icon and item quantity.
    /// \param item the item class we want to display
    /// \param order    the order in which the item should go to.
    ///
    void displayItemAtLocation(ItemsClass* item, int order);

    ///
    /// \brief resetDisplay delete all items currently on display
    ///
    void resetDisplay();

    ///
    /// \brief findIndexInList get the order of the item in the inventory
    /// \param item the item we are searching for.
    /// \return an int index representing the order the item is in.
    ///
    int findIndexInList(ItemEnumClass item);


    ///
    /// \brief replaceItemInList  replace the same item in the list with this item
    ///         (replaces quantity but gets rid of the enitre previous item)
    /// \param item the new item in the inventory
    ///
    void replaceItemInList(ItemsClass* item);

    void clearLayout(QLayout* layout);


public slots:

    ///
    /// \brief setThisItemInView replace the current item type in the inventory with this item.
    ///     This will update the quantity.
    /// \param item the item to replace or add (if the item is not inventory)
    ///
    void setThisItemInView(ItemsClass* item);

    void updateInventoryFullness(float percentage);


signals:



};

#endif // INVENTORYWIDGET_H
