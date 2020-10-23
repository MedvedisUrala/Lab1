#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <purchase_collection.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_purchase_add_clicked();

    void on_view_collection_clicked();

    void on_delete_first_clicked();

    void on_delete_queue_clicked();

    void on_size_clicked();

    void on_amount_ok_clicked();

    void on_file_input_ok_clicked();

    void on_file_output_ok_clicked();

private:
    purchase_collection *collection{collection = nullptr};
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
