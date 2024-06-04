#include "model.h"

Model::Model() {
    // Make sure they all default false.
    bariumTargeted = false;
    bauxiteTargeted = false;
    ethyleneTargeted = false;
    goldTargeted = false;
    hydrogenTargeted = false;
    ironTargeted = false;
    methaneTargeted = false;
    peridotTargeted = false;
    sulphurTargeted = false;

    inventorySize = 100;
}

float Model::totalVolumnInventory(){
    float total = 0;
    for (auto key : itemMap.keys()) {
        total += itemMap.value(key)->giveVolumn() * itemMap.value(key)->giveQuantity();
    }



    return total;
}



// Slots:
void Model::addThisItem(ItemsClass* daItem){

    // Is there room in the inventory to add this?
    if((daItem->giveQuantity() * daItem->giveVolumn()) <= (inventorySize - totalVolumnInventory())){

        // Is the item in the inventory already?
        if(itemMap.contains(daItem->giveID())){
            // Found: Add item to inventory
            itemMap.value(daItem->giveID())->addItemQuantity(daItem);

            // If the item quantity is 0 remove it from inventory, otherwise just add it
            if(itemMap.find(daItem->giveID()).value()->giveQuantity() <= 0){
                emit updateInventoryDisplay(itemMap.value(daItem->giveID()));
                itemMap.remove(daItem->giveID());

            } else {
                emit updateInventoryDisplay(itemMap.value(daItem->giveID()));
            }

        } else {
            // Not Found: As long as the item is positive, add it to inventory
            if(daItem->giveQuantity() > 0){
                itemMap.insert(daItem->giveID(), daItem);
                emit updateInventoryDisplay(daItem);
            }

        }
        // Update the progress bar!
        float percentage = (totalVolumnInventory() / inventorySize) * 100;
        emit updateInventoryFullness(percentage);
    }

}





void Model::mineOre(){

    if(bariumTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::BARIUMORE, 2);
        emit addMined(itemToAdd);
    }
    if(ironTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::IRONORE, 4);
        emit addMined(itemToAdd);
    }
    if(goldTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::GOLDORE, 2);
        emit addMined(itemToAdd);
    }
    if(ethyleneTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::ETHYLENEGAS, 1);
        emit addMined(itemToAdd);
    }
    if(peridotTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::PERIDOTGEM, 1);
        emit addMined(itemToAdd);
    }
    if(hydrogenTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::HYDROGENGAS, 2);
        emit addMined(itemToAdd);
    }
    if(sulphurTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::SULPHURORE, 3);
        emit addMined(itemToAdd);
    }
    if(methaneTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::METHANEGAS, 1);
        emit addMined(itemToAdd);
    }
    if(bauxiteTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::BAUXITEORE, 3);
        emit addMined(itemToAdd);
    }

}



void Model::dumpOre(){
    // Create an item that represents removing ore.
    // the negative numbers are for calculating the quantity
    if(bariumTargeted){
        ItemsClass* itemToAdd = new ItemsClass(ItemEnumClass::BARIUMORE, -2);
        emit addMined(itemToAdd);
    }
    if(ironTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::IRONORE, -4);
        emit addMined(itemToAdd);
    }
    if(goldTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::GOLDORE, -2);
        emit addMined(itemToAdd);
    }
    if(ethyleneTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::ETHYLENEGAS, -1);
        emit addMined(itemToAdd);
    }
    if(peridotTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::PERIDOTGEM, -1);
        emit addMined(itemToAdd);
    }
    if(hydrogenTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::HYDROGENGAS, -2);
        emit addMined(itemToAdd);
    }
    if(sulphurTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::SULPHURORE, -3);
        emit addMined(itemToAdd);
    }
    if(methaneTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::METHANEGAS, -1);
        emit addMined(itemToAdd);
    }
    if(bauxiteTargeted){
        ItemsClass *itemToAdd = new ItemsClass(ItemEnumClass::BAUXITEORE, -3);
        emit addMined(itemToAdd);
    }
}



void Model::oreTargetBool(ItemEnumClass oreID, bool isTargeted){

    switch(oreID){
        case ItemEnumClass::BARIUMORE:
            bariumTargeted = isTargeted;
            break;
        case ItemEnumClass::IRONORE:
            ironTargeted = isTargeted;
            break;
        case ItemEnumClass::GOLDORE:
            goldTargeted = isTargeted;
            break;
        case ItemEnumClass::ETHYLENEGAS:
            ethyleneTargeted = isTargeted;
            break;
        case ItemEnumClass::PERIDOTGEM:
            peridotTargeted = isTargeted;
            break;
        case ItemEnumClass::HYDROGENGAS:
            hydrogenTargeted = isTargeted;
            break;
        case ItemEnumClass::SULPHURORE:
            sulphurTargeted = isTargeted;
            break;
        case ItemEnumClass::METHANEGAS:
            methaneTargeted = isTargeted;
            break;
        case ItemEnumClass::BAUXITEORE:
            bauxiteTargeted = isTargeted;
            break;
    }
}








