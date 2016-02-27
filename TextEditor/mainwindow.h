#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_file_triggered();
    void on_actionAbout_triggered();

private:
    QPlainTextEdit * editor;
    QString url;
    Ui::MainWindow *ui;
    void savefile(QString fileurl);
    void savefiles();
    void savefile();
    void openfile();
    void newfile();
};

#endif // MAINWINDOW_H
