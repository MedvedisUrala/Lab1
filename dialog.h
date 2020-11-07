#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
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

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
