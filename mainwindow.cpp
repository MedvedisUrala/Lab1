#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "bonus_card.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include <iostream>

void MainWindow::on_purchase_add_clicked()
{
    std:: string time  = ui->purchase_time->text().toStdString();
    std:: string date  = ui->purchase_date->text().toStdString();
    int amount  = atoi(ui->purchase_amount->text().toStdString().c_str());
    auto pur = new purchase(time, date, amount);
    if(pur->get_time() == "00:00:00" || pur->get_date() == "01:01:1970" || pur->get_amount() == 0)
        QMessageBox::critical(this,"Add", "Wrong data. Please, try again");
    else
    {
            this->collection.push(*pur);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}



void MainWindow::on_view_collection_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(&this->collection, this->collection.size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");

}

void MainWindow::on_delete_first_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.pop();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}

void MainWindow::on_delete_queue_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.clear();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void MainWindow::on_size_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->collection.size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}



void MainWindow::on_amount_ok_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        std:: string time_from  = ui->amount_time_from->text().toStdString();
        std:: string date_from  = ui->amount_date_from->text().toStdString();
        std:: string time_to  = ui->amount_time_to->text().toStdString();
        std:: string date_to  = ui->amount_date_to->text().toStdString();
        QMessageBox::information(this, "Sum", "The total amount in this period is " + QString::number(this->collection.sum(time_from, date_from,time_to,date_to)));
    }
    else
        QMessageBox::critical(this,"Sum", "There is no queue");
}

void MainWindow::on_file_input_ok_clicked()
{
    this->collection.input_from_file(ui->file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void MainWindow::on_file_output_ok_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.output_to_file(ui->file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}

void MainWindow::on_bc_purchase_add_clicked()
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
        this->collection.push(*card);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}

void MainWindow::on_bc_view_collection_clicked()
{

    if(this->collection.get_iterator() && this->collection.size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(&this->collection, this->collection.size());
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");
}


void MainWindow::on_bc_size_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->collection.size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}

void MainWindow::on_bc_delete_queue_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.clear();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void MainWindow::on_bc_delete_first_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.pop();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}

void MainWindow::on_bc_amount_ok_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        std:: string time_from  = ui->bc_amount_time_from->text().toStdString();
        std:: string date_from  = ui->bc_amount_date_from->text().toStdString();
        std:: string time_to  = ui->bc_amount_time_to->text().toStdString();
        std:: string date_to  = ui->bc_amount_date_to->text().toStdString();
        QMessageBox::information(this, "Sum", "The total amount in this period is " + QString::number(this->collection.sum(time_from, date_from,time_to,date_to)));
    }
    else
        QMessageBox::critical(this,"Sum", "There is no queue");
}

void MainWindow::on_bc_file_input_ok_clicked()
{
    this->collection.bc_input_from_file(ui->bc_file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void MainWindow::on_bc_file_output_ok_clicked()
{
    if(this->collection.get_iterator() && this->collection.size())
    {
        this->collection.output_to_file(ui->bc_file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    this->collection.clear();
}
