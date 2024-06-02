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
    ///
    /// \brief addThisItem add the item to the inventory and update display
    /// \param daItem
    ///
    void addThisItem(ItemsClass *daItem);

    ///
    /// \brief oreTargetBool  toggles the targeted item so we know what to add to inventory
    /// \param itemID
    /// \param isTargeted   the state to set the items bool
    ///
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
    ///
    /// \brief updateInventoryDisplay  tell inventoryWidget to display this item
    /// \param ItemsClass
    ///
    void updateInventoryDisplay(ItemsClass* ItemsClass);

    ///
    /// \brief replaceInventoryItem  tell inventoryWidget to replace item on display with this one
    /// \param itemToReplace
    ///
    void replaceInventoryItem(ItemsClass* itemToReplace);

    ///
    /// \brief addMined  add item to inventory with threading
    /// \param daItem
    ///
    void addMined(ItemsClass *daItem);

    ///
    /// \brief removeDumped  remove item from inventory with threading
    /// \param daItem
    ///
    void removeDumped(ItemsClass *daItem);



};

#endif // MODEL_H




