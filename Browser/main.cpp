#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog view;
    view.setWindowTitle("Browser");
    view.show();

    return a.exec();
}
