#ifndef BC_WINDOW_H
#define BC_WINDOW_H

#include <QDialog>
#include <purchase_collection.h>

namespace Ui {
class bc_window;
}

class bc_window : public QDialog
{
    Q_OBJECT

public:
    explicit bc_window(QWidget *parent = nullptr);
    ~bc_window();

private slots:

    void on_bc_purchase_add_clicked();


    void on_bc_view_collection_clicked();

    void on_bc_size_clicked();

    void on_bc_delete_queue_clicked();

    void on_bc_delete_first_clicked();

    void on_bc_amount_ok_clicked();

    void on_bc_file_input_ok_clicked();

    void on_bc_file_output_ok_clicked();


    void on_pushButton_bc_back_clicked();

private:
    purchase_collection bc_collection;
    Ui::bc_window *ui;
};

#endif // BC_WINDOW_H
