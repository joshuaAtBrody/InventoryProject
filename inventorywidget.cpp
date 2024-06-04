

#include "inventorywidget.h"
#include "ui_inventorywidget.h"

InventoryWidget::InventoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InventoryWidget)
{
    ui->setupUi(this);
}

InventoryWidget::~InventoryWidget()
{
    delete ui;
    qDeleteAll(itemsMap);

    //delete mainLayout;
}

// Slot

void InventoryWidget::setThisItemInView(ItemsClass* item){
    replaceItemInList(item);
}



void InventoryWidget::updateInventoryFullness(float percentage){
    ui->InventoryFullnessBar->setValue(percentage);
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


// reorder all items in list
void InventoryWidget::resetDisplay(){
    clearLayout(ui->gridLayout);

    for (auto key : itemsMap.keys()) {
        int order = findIndexInList(key);
        displayItemAtLocation(itemsMap.value(key), order);
    }
}


void InventoryWidget::clearLayout(QLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Delete the widget
        } else if (item->layout()) {
            clearLayout(item->layout());  // Recursively clear nested layouts
            delete item->layout();  // Delete the nested layout
        }
        delete item;  // Delete the layout item
    }
}




int InventoryWidget::findIndexInList(ItemEnumClass item){
    auto it = std::find(itemsOrder.begin(), itemsOrder.end(), item);

    if(it != itemsOrder.end()){
        // return the index the item was found at.
        return std::distance(itemsOrder.begin(), it);
    }


    return 0; // Item not found
}




void InventoryWidget::replaceItemInList(ItemsClass* itemToReplace){
    // Check if the itemToAdd is in the map already
    if(itemsMap.contains(itemToReplace->giveID())){



        // The item reached 0, time to get rid of it!
        if(itemsMap.value(itemToReplace->giveID())->giveQuantity() <= 0){
            itemsMap.remove(itemToReplace->giveID());

            // Use std::remove to move the elements to be removed to the end
            auto newEnd = std::remove(itemsOrder.begin(), itemsOrder.end(), itemToReplace->giveID());



            // Erase the elements from the new end to the actual end
            itemsOrder.erase(newEnd, itemsOrder.end());

            resetDisplay();



        } else {
            itemsMap.insert(itemToReplace->giveID(), itemToReplace);
            int order = findIndexInList(itemToReplace->giveID());
            displayItemAtLocation(itemToReplace, order);
        }

    } else {
        // Not Found: so just add the item.
        itemsMap.insert(itemToReplace->giveID(), itemToReplace);
        itemsOrder.push_back(itemToReplace->giveID());

        int order = findIndexInList(itemToReplace->giveID());
        displayItemAtLocation(itemToReplace, order);
    }
}








