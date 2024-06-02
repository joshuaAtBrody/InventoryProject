#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new Model)
{
    ui->setupUi(this);

    setUpConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


// Private:
void MainWindow::setUpConnections(){
    connect(this, &MainWindow::addItemToInventory, model, &Model::addThisItem);
    connect(this, &MainWindow::mined, model, &Model::mineOre);
    connect(this, &MainWindow::dumped, model, &Model::dumpOre);
    connect(this, &MainWindow::oreToggled, model, &Model::oreTargetBool);


    connect(model, &Model::updateInventoryDisplay, this, &MainWindow::replaceInventoryItem);


    connect(model, &Model::addMined, model, &Model::addThisItem);



}



// Slots:


void MainWindow::replaceInventoryItem(ItemsClass* itemToReplace){
    ui->invWig->setThisItemInView(itemToReplace);
}

void MainWindow::on_mineButton_clicked()
{
    emit mined();
}


void MainWindow::on_dumpButton_clicked()
{
    emit dumped();
}





void MainWindow::on_bauxiteTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::BAUXITEORE, checked);
}


void MainWindow::on_ethyleneTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::ETHYLENEGAS, checked);
}


void MainWindow::on_peridotTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::PERIDOTGEM, checked);
}


void MainWindow::on_hydrogenTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::HYDROGENGAS, checked);
}


void MainWindow::on_sulphurTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::SULPHURORE, checked);
}


void MainWindow::on_methaneTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::METHANEGAS, checked);
}


void MainWindow::on_ironTarget0_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::IRONORE, checked);

}


void MainWindow::on_bariumOTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::BARIUMORE, checked);

}


void MainWindow::on_goldTarget_toggled(bool checked)
{
    emit oreToggled(ItemEnumClass::GOLDORE, checked);

}

