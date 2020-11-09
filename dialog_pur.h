#ifndef DIALOG_PUR_H
#define DIALOG_PUR_H

#include <QDialog>
#include "purchase_collection.h"

namespace Ui {
class Dialog_pur;
}

class Dialog_pur : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_pur(QWidget *parent = nullptr);
    void input_prod(Ui::Dialog_pur *ui);
    void input_lim_prod(Ui::Dialog_pur *ui);
    ~Dialog_pur();

private slots:
    void on_pushButton_add_prod_pur_clicked();

    void on_pushButton_add_lim_prod_pur_clicked();

    void on_pushButton_check_del_pur_clicked();

private:
    purchase_collection bc_collection;
    Ui::Dialog_pur *ui;
};

#endif // DIALOG_PUR_H
