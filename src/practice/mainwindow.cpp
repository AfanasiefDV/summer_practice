#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_guiInput_clicked()
{
    emit guiInput();
}

void MainWindow::on_fileInput_clicked()
{
    emit fileInput();
}

void MainWindow::on_exitApp_clicked()
{
    qApp->quit();
}
