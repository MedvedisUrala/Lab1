#include "purchase_window.h"
#include "ui_purchase_window.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "bonus_card.h"
#include "mainwindow.h"
#include <fstream>

purchase_window::purchase_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchase_window)
{
    ui->setupUi(this);
    this->pur_collection.input_from_file("save_pur.txt");
}

void purchase_window::on_purchase_add_clicked()
{
    std:: string time  = ui->purchase_time->text().toStdString();
    std:: string date  = ui->purchase_date->text().toStdString();
    int amount  = atoi(ui->purchase_amount->text().toStdString().c_str());
    auto pur = new purchase(time, date, amount);
    if(pur->get_time() == "00:00:00" || pur->get_date() == "01:01:1970" || pur->get_amount() == 0)
        QMessageBox::critical(this,"Add", "Wrong data. Please, try again");
    else
    {
            this->pur_collection.push(*pur);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}



void purchase_window::on_view_collection_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(&this->pur_collection, this->pur_collection.size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");

}

void purchase_window::on_delete_first_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        this->pur_collection.pop();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}

void purchase_window::on_delete_queue_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        this->pur_collection.clear();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void purchase_window::on_size_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->pur_collection.size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}



void purchase_window::on_amount_ok_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        std:: string time_from  = ui->amount_time_from->text().toStdString();
        std:: string date_from  = ui->amount_date_from->text().toStdString();
        std:: string time_to  = ui->amount_time_to->text().toStdString();
        std:: string date_to  = ui->amount_date_to->text().toStdString();
        QMessageBox::information(this, "Sum", "The total amount in this period is " + QString::number(this->pur_collection.sum(time_from, date_from,time_to,date_to)));
    }
    else
        QMessageBox::critical(this,"Sum", "There is no queue");
}

void purchase_window::on_file_input_ok_clicked()
{
    this->pur_collection.input_from_file(ui->file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void purchase_window::on_file_output_ok_clicked()
{
    if(this->pur_collection.get_iterator() && this->pur_collection.size())
    {
        this->pur_collection.output_to_file(ui->file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}

purchase_window::~purchase_window()
{
    delete ui;
}

void pur_save_data(const purchase_collection& col)
{
    ofstream fout("save_pur.txt");
    for(int i = 0;i < col.get_count();i++)
    {
        fout << col.get_iterator()[i]->get_time()<< endl;
        fout << col.get_iterator()[i]->get_date() << endl;
        fout << col.get_iterator()[i]->get_amount() << endl;
    }
    fout.close();
}

void purchase_window::on_pushButton_clicked()
{

    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No)
    {
        pur_collection.clear();
    }
    pur_save_data(pur_collection);
    this->close();
}
