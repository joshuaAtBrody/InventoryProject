/* This class will store the player's inventory.
 * Update the inventory, tell inventory widget to display the inventory.
 * Know what is being targeted and the player's coordinates (soon).
 */

#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVector>
#include "itemslot.h"
#include "itemsclass.h"
#include "itemenumclass.h"

class Model : public QObject // Inherit from QObject
{
    Q_OBJECT // Add the Q_OBJECT macro to enable signals and slots

public:
    Model();

private:
    // Key: item name, Value: itemSlot(stores png and name). Is used to tell invetoryWidget to display these ItemSlots

    std::vector<ItemsClass*> itemStorage;
    QMap<ItemEnumClass, ItemsClass*> itemMap;

    bool bariumTargeted;
    bool ironTargeted;
    bool goldTargeted;
    bool ethyleneTargeted;
    bool peridotTargeted;
    bool hydrogenTargeted;
    bool sulphurTargeted;
    bool methaneTargeted;
    bool bauxiteTargeted;



public slots:
    void addThisItem(ItemsClass *daItem);
    void removeThisItem(ItemsClass *daItem);

    void oreTargetBool(ItemEnumClass itemID, bool isTargeted);

    /**
     * @brief mineOre calculate the ore mined and add that ore and quantity through addMined
     */
    void mineOre();

    /**
     * @brief dumpOre remove the ore selected with removeDumped
     */
    void dumpOre();


signals:
    void updateInventoryDisplay(ItemsClass* ItemsClass);
    void replaceInventoryItem(ItemsClass* itemToReplace);

    void addMined(ItemsClass *daItem);
    void removeDumped(ItemsClass *daItem);



};

#endif // MODEL_H




