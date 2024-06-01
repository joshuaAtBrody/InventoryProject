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
    ///
    /// \brief updateInventory tell display to add this item quantity
    /// \param itemToRefresh
    ///
    void updateInventory(ItemsClass* itemToRefresh);

    ///
    /// \brief replaceInventoryItem  tell display to replace the same item with this one.
    /// \param itemToReplace
    ///
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

    ///
    /// \brief addItemToInventory  tell model to add this item
    /// \param daItem
    ///
    void addItemToInventory(ItemsClass* daItem);

    ///
    /// \brief removeItemFromInventory  tell model to remove this item
    /// \param daItem
    ///
    void removeItemFromInventory(ItemsClass* daItem);

    ///
    /// \brief mined tell model to add items that have been toggled
    ///
    void mined();

    ///
    /// \brief dumped  tell model to remove items that have been toggled
    ///
    void dumped();

    ///
    /// \brief oreToggled tell model to toggle the current item marked
    /// \param itemID   the item that will be toggled
    /// \param checked  the toggle state
    ///
    void oreToggled(ItemEnumClass itemID, bool checked);



private:
    Ui::MainWindow *ui;
    Model *model;
    void setUpConnections();
};
#endif // MAINWINDOW_H
