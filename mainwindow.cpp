#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>

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
    purchase pur(time, date, amount);
    if(pur.get_time() == "00:00:00" || pur.get_date() == "01:01:1970" || pur.get_amount() == 0)
        QMessageBox::critical(this,"Add", "Wrong data. Please, try again");
    else
    {
        if(!this->collection)
            this->collection = new purchase_collection(pur);
        else
            this->collection->push(pur);
        QMessageBox::information(this, "Add", "You add new purchase");
    }
}



void MainWindow::on_view_collection_clicked()
{
    if(this->collection && this->collection->size())
    {
        second_window window;
        window.setModal(true);
        window.insert_data(this->collection);
        window.exec();
    }
    else
        QMessageBox::critical(this,"Show", "There is no data to show");

}

void MainWindow::on_delete_first_clicked()
{
    if(this->collection && this->collection->size())
    {
        this->collection->pop();
        QMessageBox::information(this, "Pop", "You pop first purchase");
    }
    else
        QMessageBox::critical(this,"Pop", "There is no data to pop");
}

void MainWindow::on_delete_queue_clicked()
{
    if(this->collection && this->collection->size())
    {
        this->collection->clear();
        QMessageBox::information(this, "Clean", "You delete all queue");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void MainWindow::on_size_clicked()
{
    if(this->collection && this->collection->size())
    {
        QMessageBox::information(this, "Size", "The size of the queue is " + QString::number(this->collection->size()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no queue");
}



void MainWindow::on_amount_ok_clicked()
{
    if(this->collection && this->collection->size())
    {
        std:: string time_from  = ui->amount_time_from->text().toStdString();
        std:: string date_from  = ui->amount_date_from->text().toStdString();
        std:: string time_to  = ui->amount_time_to->text().toStdString();
        std:: string date_to  = ui->amount_date_to->text().toStdString();
        QMessageBox::information(this, "Sum", "The total amount in this period is " + QString::number(this->collection->sum(time_from, date_from,time_to,date_to)));
    }
    else
        QMessageBox::critical(this,"Sum", "There is no queue");
}

void MainWindow::on_file_input_ok_clicked()
{
    if(!this->collection)
        this->collection = new purchase_collection;
    this->collection->input_from_file(ui->file_input_name->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void MainWindow::on_file_output_ok_clicked()
{
    if(this->collection && this->collection->size())
    {
        this->collection->output_to_file(ui->file_output_name->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no queue");
}
