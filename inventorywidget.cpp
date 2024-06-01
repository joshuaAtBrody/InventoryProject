

#include "inventorywidget.h"
#include "ui_inventorywidget.h"

InventoryWidget::InventoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InventoryWidget)
{
    ui->setupUi(this);

    // mainLayout = new QVBoxLayout(this);
    // ui->scrollAreaWidgetContents->setLayout(mainLayout);
}

InventoryWidget::~InventoryWidget()
{
    delete ui;
    //delete mainLayout;
}

// Slot
void InventoryWidget::updateWithItem(ItemsClass* item){

    // Add item to the list. Will return the item with updated quantity.
    ItemsClass* updatedItem = updateItemInList(item); // If not in list, add it
    int order = findIndexInList(updatedItem); // if item not in list, return 0!
    displayItemAtLocation(updatedItem, order);
}

void InventoryWidget::setThisItemInView(ItemsClass* item){
    replaceItemInList(item);

    int order = findIndexInList(item);
    displayItemAtLocation(item, order);
}


// Private:
void InventoryWidget::displayItemAtLocation(ItemsClass* item, int order){
    // Create item slot

    QWidget* widget = new QWidget;
    widget->setBaseSize(85, 64);

    QLabel *nameLabel = new QLabel(item->giveName());
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setFixedSize(QSize(64, 64)); // 64x64 for image

    QLabel *quantityLabel = new QLabel(QString::number(item->giveQuantity()));
    quantityLabel->setAlignment(Qt::AlignCenter);
    quantityLabel->setFixedSize(64, 20);

    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(nameLabel);
    layout->addWidget(quantityLabel);
    widget->setLayout(layout);

    // Calculate which inventory slot to take up based on order of itemList.
    int row = order / 8;
    int col = order % 8;

    ui->gridLayout->addWidget(widget, row, col, Qt::AlignTop | Qt::AlignLeft);

}


// delete all items
void InventoryWidget::resetDisplay(){

}



int InventoryWidget::findIndexInList(ItemsClass* item){
    auto it = std::find(itemsMap.begin(), itemsMap.end(), item);

    if(it != itemsMap.end()){
        // return the index the item was found at.
        return std::distance(itemsMap.begin(), it);
    }


    return 0; // Item not found
}



ItemsClass* InventoryWidget::updateItemInList(ItemsClass* itemWantToAdd){
    if(itemsMap.contains(itemWantToAdd->giveID())){
        itemsMap.find(itemWantToAdd->giveID()).value()->addItemQuantity(itemWantToAdd);
        return itemsMap.value(itemWantToAdd->giveID());

    } else {
        itemsMap.insert(itemWantToAdd->giveID(), itemWantToAdd);
        return itemWantToAdd;
    }
}

void InventoryWidget::replaceItemInList(ItemsClass* itemToReplace){
    if(itemsMap.contains(itemToReplace->giveID())){
        itemsMap.remove(itemToReplace->giveID());
        itemsMap.insert(itemToReplace->giveID(), itemToReplace);
    }
}








