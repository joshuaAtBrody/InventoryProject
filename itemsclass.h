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

    void addItemQuantity(ItemsClass* itemToAdd);


private:
    ItemEnumClass itemID;
    QString name;
    QString imagePath;
    QString description;
    float weight;
    float volumn; // The space the item takes up.
    int sellValue;

    int quantity;

    void setStats(QString name, QString imagePath, QString description, float weight, float volumn, int sellValue);

    // item group? (ore, gun, currency, etc)?
};

#endif // ITEMSCLASS_H
