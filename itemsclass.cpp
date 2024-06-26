#include "itemsclass.h"

ItemsClass::ItemsClass() {
    name = "";
    imagePath = "";
    description = "";
    weight = 0;
    volumn = 0;
    sellValue = 0;
}

ItemsClass::ItemsClass(ItemEnumClass itemID, int quantity) : itemID(itemID), quantity(quantity){
    switch(itemID){
        case ItemEnumClass::BARIUMORE:
            setStats("Barium Ore", "", "", 2.5, .7, 0);
            break;
        case ItemEnumClass::BAUXITEORE:
            setStats("Bauxite Ore", "", "", 2.5, .65, 0);
            break;
        case ItemEnumClass::ETHYLENEGAS:
            setStats("Ethylene Gas", "", "", .1, .025, 0);
            break;
        case ItemEnumClass::GOLDORE:
            setStats("Gold Ore", "", "", 5, 1, 0);
            break;
        case ItemEnumClass::HYDROGENGAS:
            setStats("Hydrogen Gas", "", "", 1, .1, 0);
            break;
        case ItemEnumClass::IRONORE:
            setStats("Iron Ore", "", "", 4.75, .75, 0);
            break;
        case ItemEnumClass::METHANEGAS:
            setStats("Methane Gas", "", "", .2, .05, 0);
            break;
        case ItemEnumClass::PERIDOTGEM:
            setStats("Peridot Gem", "", "", 2.25, .2, 0);
            break;
        case ItemEnumClass::SULPHURORE:
            setStats("Sulphur Ore", "", "", .75, .075, 0);
            break;
    }
}

// destructor
ItemsClass::~ItemsClass(){

}


// Private:
ItemEnumClass ItemsClass::giveID(){
    return itemID;
}

QString ItemsClass::giveName(){
    return name;
}

QString ItemsClass::givePath(){
    return imagePath;
}

QString ItemsClass::giveDesc(){
    return description;
}

int ItemsClass::giveQuantity(){
    return quantity;
}

float ItemsClass::giveVolumn(){
    return volumn;
}


void ItemsClass::addItemQuantity(ItemsClass* item){
    quantity += item->giveQuantity();
}

void ItemsClass::setStats(QString nameP, QString imagePathP, QString descriptionP, float weightP, float volumnP, int sellValueP){
    name = nameP;
    imagePath = imagePathP;
    description = descriptionP;
    weight = weightP;
    volumn = volumnP;
    sellValue = sellValueP;
}

















