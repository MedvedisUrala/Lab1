#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
#include "purchase_collection.h"
using namespace  std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void input_prod(Ui::Dialog *ui);
    void input_lim_prod(Ui::Dialog *ui);
    ~Dialog();

private slots:
    void on_pushButton_add_prod_clicked();

    void on_pushButton_add_lim_prod_clicked();

    void on_pushButton_check_del_clicked();

    void on_pushButton_pay_clicked();

    void on_pushButton_num_card_ok_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_clicked();

private:
    purchase_collection bc_collection;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
