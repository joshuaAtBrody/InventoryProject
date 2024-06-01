#include "itemslot.h"
#include "ui_itemslot.h"

ItemSlot::ItemSlot(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ItemSlot)
{
    ui->setupUi(this);
}




ItemSlot::~ItemSlot()
{
    delete ui;
}

void ItemSlot::stuffSlot(QString itemName, QString itemImagePath){
    ui->itemNameLabel->setText(itemName);

    QImage daImage;
    if (!daImage.load(itemImagePath)) { // Path had error
        //qWarning() << "Failed to load image:" << itemImagePath;
        //ui->itemImageLabel->clear();
        ui->itemImageLabel->setText("broken lol");
    } else { // Path loaded image
        daImage = daImage.scaled(128, 128);
        ui->itemImageLabel->setPixmap(QPixmap::fromImage(daImage));
    }


    // Store the variables.
    varItemName = itemName;
    varItemImagePath = itemImagePath;
}



