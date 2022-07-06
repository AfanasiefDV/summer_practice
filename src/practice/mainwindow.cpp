#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graficUI = new InputGuiWindow();
    fileUI = new InputWindow();
    connect(fileUI, &InputWindow::backToWindow, this, &MainWindow::show );
    connect(graficUI, &InputGuiWindow::backToWindow, this, &MainWindow::show );
}

MainWindow::~MainWindow()
{
    delete fileUI;
    delete graficUI;
    delete ui;
}

void MainWindow::on_guiInput_clicked()
{
    graficUI->show();
    this->close();
}

void MainWindow::on_fileInput_clicked()
{
    fileUI->show();
    this->close();
}

void MainWindow::on_exitApp_clicked()
{
    qApp->quit();
}
