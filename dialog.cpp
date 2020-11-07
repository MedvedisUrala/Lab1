#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <string>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    input_prod(ui);
    input_lim_prod(ui);
}

void Dialog::input_prod(Ui::Dialog *ui)
{
    string item;
    ifstream file("prod.txt");


    if (file.is_open())
    {
        while(!file.eof())
        {
            getline(file, item);
            ui->listWidget_prod->addItem(QString::fromStdString(item));
        }
        file.close();
    }
}

void Dialog::input_lim_prod(Ui::Dialog *ui)
{

    string item;
    ifstream file("lim_prod.txt");


    if (file.is_open())
    {
        while(!file.eof())
        {
            getline(file, item);
            ui->listWidget_lim_prod->addItem(QString::fromStdString(item));
        }
        file.close();
    }
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_add_prod_clicked()
{
    ui->listWidget_check->addItem(ui->listWidget_prod->currentItem()->text());
}

void Dialog::on_pushButton_add_lim_prod_clicked()
{
    ui->listWidget_check->addItem(ui->listWidget_lim_prod->currentItem()->text());
}

void Dialog::on_pushButton_check_del_clicked()
{
    ui->listWidget_check->takeItem(ui->listWidget_check->currentRow());
}
