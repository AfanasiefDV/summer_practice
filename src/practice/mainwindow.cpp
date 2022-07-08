#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //graficUI = new InputGuiWindow();
    //fileUI = new InputWindow();
    //connect(fileUI, &InputWindow::backToWindow, this, &MainWindow::show );
    //connect(graphicUI, &InputGuiWindow::backToWindow, this, &MainWindow::show );
    //connect(parUI, &ParametersWindow::backToWindow, this, &MainWindow::show );
    //connect(gaUI, &GAWindow::backToWindow, this, &MainWindow::show );

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_guiInput_clicked()
{
    //graphicUI->show();
    this->close();
}

void MainWindow::on_fileInput_clicked()
{
    //fileUI->show();
    this->close();
}

void MainWindow::on_exitApp_clicked()
{
    qApp->quit();
}
