#include "second_window.h"
#include "ui_second_window.h"
#include "purchase_collection.h"
#include <QStandardItem>
#include <QStandardItemModel>

second_window::second_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_window)
{
    ui->setupUi(this);
}

second_window::~second_window()
{
    delete ui;
}

void second_window::on_pushButton_clicked()
{
    hide();
}

void second_window::insert_data(purchase_collection* collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i = 0; i < size;i++)
    {
        item = new QStandardItem(QString("#" + QString::number(i+1)));
        model->appendRow(item);
        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_data("date"))));
        model->appendRow(item);
        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_data("time"))));
        model->appendRow(item);
        item = new QStandardItem(QString(QString::number(collection->get_iterator()[i]->get_amount())));
        model->appendRow(item);
        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_data("card"))));
        model->appendRow(item);
        item = new QStandardItem(QString(QString::fromStdString(collection->get_iterator()[i]->get_data("tele"))));
        model->appendRow(item);
        item = new QStandardItem(QString("   "));
        model->appendRow(item);
    }
    ui->listView->setModel(model);
}
