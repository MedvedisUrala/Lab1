#include "dialog_pur.h"
#include "ui_dialog_pur.h"
#include <fstream>
#include <QMessageBox>
#include "bc_window.h"
#include "purchase_window.h"

Dialog_pur::Dialog_pur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_pur)
{
    ui->setupUi(this);
    input_prod(ui);
    input_lim_prod(ui);
    this->bc_collection.input_from_file("save_pur.txt");
}

void Dialog_pur::input_prod(Ui::Dialog_pur *ui)
{
    string item;
    ifstream file("prod.txt");


    if (file.is_open())
    {
        while(!file.eof())
        {
            getline(file, item);
            ui->listWidget_prod_pur->addItem(QString::fromStdString(item));
        }
        file.close();
    }
}

void Dialog_pur::input_lim_prod(Ui::Dialog_pur *ui)
{

    string item;
    ifstream file("lim_prod.txt");


    if (file.is_open())
    {
        while(!file.eof())
        {
            getline(file, item);
            ui->listWidget_lim_prod_pur->addItem(QString::fromStdString(item));
        }
        file.close();
    }
}


Dialog_pur::~Dialog_pur()
{
    delete ui;
}

void Dialog_pur::on_pushButton_add_prod_pur_clicked()
{
    char *item = (char *)ui->listWidget_prod_pur->currentItem()->text().toStdString().c_str();
    while(!isdigit(*item))
        item++;
    int price_item = atoi(item);
    int amount = ui->label_amount_pur->text().toInt();
    ui->label_amount_pur->setNum(price_item + amount);
    ui->listWidget_check_pur->addItem(ui->listWidget_prod_pur->currentItem()->text());
}

void Dialog_pur::on_pushButton_add_lim_prod_pur_clicked()
{
    char *item = (char *)ui->listWidget_lim_prod_pur->currentItem()->text().toStdString().c_str();
    while(!isdigit(*item))
        item++;
    int price_item = atoi(item);
    int amount = ui->label_amount_pur->text().toInt();
    ui->label_amount_pur->setNum(price_item + amount);
    ui->listWidget_check_pur->addItem(ui->listWidget_lim_prod_pur->currentItem()->text());

}

void Dialog_pur::on_pushButton_check_del_pur_clicked()
{
    char *item = (char *)ui->listWidget_check_pur->currentItem()->text().toStdString().c_str();
    while(!isdigit(*item))
        item++;
    int price_item = atoi(item);
    int amount = ui->label_amount_pur->text().toInt();
    ui->label_amount_pur->setNum(amount - price_item);
    ui->listWidget_check_pur->takeItem(ui->listWidget_check_pur->currentRow());

}

void Dialog_pur::on_pushButton_back_pur_clicked()
{

    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No)
    {
        this->bc_collection.clear();
    }
    bc_save_data(this->bc_collection);
    this->close();
}

void Dialog_pur::on_pushButton_pay_pur_clicked()
{
    QMessageBox::information(this,"Purchase", "Thanks for you visit!\nTotal amount is " + ui->label_amount_pur->text());
    char buffer[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format_time = "%X";
    char* format_day = "%d:%m:%Y";
    strftime(buffer, 80, format_time, timeinfo);
    string time = string(buffer);
    strftime(buffer, 80, format_day, timeinfo);
    string date = string(buffer);
    auto pur = new purchase(time,date,ui->label_amount_pur->text().toInt());
    this->bc_collection.push(*pur);


    ui->listWidget_check_pur->clear();
    ui->label_amount_pur->setText(QString::number(0));
}

void Dialog_pur::on_pushButton_about_pur_clicked()
{
    pur_save_data(this->bc_collection);
    purchase_window window;
    window.set_dialog_coll(&this->bc_collection);
    window.setModal(true);
    window.exec();
}
