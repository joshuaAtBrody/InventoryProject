/* Creates an independent item with all attributes.
 * By Joshua Brody 5/2024
 *
 */


#ifndef ITEMSCLASS_H
#define ITEMSCLASS_H

#include <QObject>
#include "itemenumclass.h"

class ItemsClass
{
public:
    ItemsClass();
    ///
    /// \brief ItemsClass set the variables based on item ID
    /// \param itemID   the item we want to create
    /// \param quantity the amount of that item there is in this item.
    ///
    ItemsClass(ItemEnumClass itemID, int quantity);

    ~ItemsClass();

    ItemEnumClass giveID();
    QString giveName();
    QString givePath();
    QString giveDesc();
    float giveWeight();
    float giveVolumn();
    int giveSellVal();
    int giveQuantity();

    ///
    /// \brief addItemQuantity  add the other item class's quantity to this item
    /// \param itemToAdd  the other item.
    ///
    void addItemQuantity(ItemsClass* itemToAdd);


private:
    ItemEnumClass itemID;
    QString name;
    QString imagePath;
    QString description;
    float weight;
    float volumn; // The space the item takes up.
    int sellValue;

    int quantity; // for now quantity instead of volumn

    ///
    /// \brief setStats helper method to set the variables of an item.
    /// \param name
    /// \param imagePath
    /// \param description
    /// \param weight
    /// \param volumn
    /// \param sellValue
    ///
    void setStats(QString name, QString imagePath, QString description, float weight, float volumn, int sellValue);

    // item group? (ore, gun, currency, etc)?
};

#endif // ITEMSCLASS_H
