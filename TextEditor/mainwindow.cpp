#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    editor = new QPlainTextEdit();
    setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openfile()
{
    QString openfileurl = QFileDialog::getOpenFileName();
    if(openfileurl.isEmpty() || openfileurl == url) return;
    QFile file(openfileurl);
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            url = openfileurl;
            editor->setPlainText(QString::fromUtf8(file.readAll()));
            statusBar()->showMessage(tr("File %1 has been succesfull open").arg(url), 1000);
            setWindowTitle(url);
        }
        else
            statusBar()->showMessage(tr("Could not open file %1 .").arg(url), 1000);

}
void MainWindow::on_actionOpen_triggered()
{
    openfile();
}

void MainWindow::savefile()
{
    if (url.isEmpty()) { savefiles(); return; }
    QFile file(url);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(editor -> toPlainText().toUtf8());
        statusBar() -> showMessage(tr("File %1 succesfully saved.").arg(url), 1000);
    }
    else
    {
        statusBar() -> showMessage(tr("Error in saving file %1").arg(url), 1000);
    }
}
void MainWindow::savefile(QString fileurl)
{
    QFile file(fileurl);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(editor -> toPlainText().toUtf8());
        url = fileurl;
        statusBar() -> showMessage(tr("File saved") , 1000);
    }
    else
    {
        statusBar() -> showMessage(tr("Error in saving file %1").arg(url), 1000);
    }
}
void MainWindow::savefiles()
{
    QString url = QFileDialog::getSaveFileName();
    savefile(url);
}

void MainWindow::on_actionSave_file_triggered()
{
    savefile();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this , tr("About") , tr("That simple text editor was made for learning purposes using qt and c++"));
}
