/* Main View part of the project. Displays the inventory, options, ui, and more!
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inventorywidget.h"
#include "itemsclass.h"
#include "model.h"
#include "itemenumclass.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateInventory(ItemsClass* itemToRefresh);
    void replaceInventoryItem(ItemsClass* itemToReplace);


private slots:

    void on_mineButton_clicked();

    void on_dumpButton_clicked();

    void on_bauxiteTarget_toggled(bool checked);

    void on_ethyleneTarget_toggled(bool checked);

    void on_peridotTarget_toggled(bool checked);

    void on_hydrogenTarget_toggled(bool checked);

    void on_sulphurTarget_toggled(bool checked);

    void on_methaneTarget_toggled(bool checked);

    void on_ironTarget0_toggled(bool checked);

    void on_bariumOTarget_toggled(bool checked);

    void on_goldTarget_toggled(bool checked);

signals:
    void addItemToInventory(ItemsClass* daItem);
    void removeItemFromInventory(ItemsClass* daItem);
    void mined();
    void dumped();

    void oreToggled(ItemEnumClass itemID, bool checked);



private:
    Ui::MainWindow *ui;
    Model *model;
    void setUpConnections();
};
#endif // MAINWINDOW_H
