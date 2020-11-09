#ifndef PURCHASE_WINDOW_H
#define PURCHASE_WINDOW_H

#include <QDialog>
#include <purchase_collection.h>

namespace Ui {
class purchase_window;
}

class purchase_window : public QDialog
{
    Q_OBJECT

public:
    explicit purchase_window(QWidget *parent = nullptr);
    void set_dialog_coll(purchase_collection *coll){this->pur_collection_dial = coll;}
    ~purchase_window();

private slots:

    void on_view_collection_clicked();

    void on_delete_first_clicked();

    void on_delete_queue_clicked();

    void on_size_clicked();

    void on_amount_ok_clicked();

    void on_file_input_ok_clicked();

    void on_file_output_ok_clicked();
    void on_pushButton_clicked();

private:
    purchase_collection pur_collection;
    purchase_collection *pur_collection_dial;
    Ui::purchase_window *ui;
};
void pur_save_data(const purchase_collection& col);

#endif // PURCHASE_WINDOW_H
