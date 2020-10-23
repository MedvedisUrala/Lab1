#include "mainwindow.h"

#include <QApplication>

#include "purchase.h"
#include "test.h"
#include "purchase_collection.h"

int main(int argc, char *argv[])
{
    test_class();
    test_collection_class();
    test_bc_class();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
