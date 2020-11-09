#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <second_window.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "bonus_card.h"
#include "purchase_window.h"
#include "bc_window.h"
#include "dialog.h"
#include "dialog_pur.h"

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

void MainWindow::on_pushButton_bc_clicked()
{
    Dialog window;
    //bc_window window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_pur_clicked()
{
    Dialog_pur window;
    //hide();
    //purchase_window window;
    window.setModal(true);
    window.exec();
}
