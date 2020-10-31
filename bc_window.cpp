#include "bc_window.h"
#include "ui_bc_window.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "bonus_card.h"
#include "mainwindow.h"

bc_window::bc_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bc_window)
{
    ui->setupUi(this);
}


void bc_window::on_bc_purchase_add_clicked()
{
    std:: string time  = ui->bc_purchase_time->text().toStdString();
    std:: string date  = ui->bc_purchase_date->text().toStdString();
    int amount  = atoi(ui->bc_purchase_amount->text().toStdString().c_str());
    std:: string bc_number  = ui->bc_purchase_bonus_card->text().toStdString();
    auto card = new bonus_card(time, date, amount, bc_number);
    if(card->get_time() == "00:00:00" || card->get_date() == "01:01:1970" || card->get_amount() == 0 || card->get_bonus_card_number() == "000000000000")
        QMessageBox::critical(this,"Add", "Wrong data. Please, try again");
    else
    {
        this->bc_collection.push(*card);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}

void bc_window::on_bc_view_collection_clicked()
{

    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(&this->bc_collection, this->bc_collection.size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");
}


void bc_window::on_bc_size_clicked()
{
    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->bc_collection.size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}

void bc_window::on_bc_delete_queue_clicked()
{
    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        this->bc_collection.clear();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void bc_window::on_bc_delete_first_clicked()
{
    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        this->bc_collection.pop();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}

void bc_window::on_bc_amount_ok_clicked()
{
    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        std:: string time_from  = ui->bc_amount_time_from->text().toStdString();
        std:: string date_from  = ui->bc_amount_date_from->text().toStdString();
        std:: string time_to  = ui->bc_amount_time_to->text().toStdString();
        std:: string date_to  = ui->bc_amount_date_to->text().toStdString();
        QMessageBox::information(this, "Sum", "The total amount in this period is " + QString::number(this->bc_collection.sum(time_from, date_from,time_to,date_to)));
    }
    else
        QMessageBox::critical(this,"Sum", "There is no queue");
}

void bc_window::on_bc_file_input_ok_clicked()
{
    this->bc_collection.bc_input_from_file(ui->bc_file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void bc_window::on_bc_file_output_ok_clicked()
{
    if(this->bc_collection.get_iterator() && this->bc_collection.size())
    {
        this->bc_collection.output_to_file(ui->bc_file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}

bc_window::~bc_window()
{
    delete ui;
}


void bc_window::on_pushButton_bc_back_clicked()
{
    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No)
    {
        bc_collection.clear();
    }
    this->close();
}
