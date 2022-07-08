#include "gawindow.h"
#include "ui_gawindow.h"

GAWindow::GAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GAWindow)
{
    ui->setupUi(this);
}

GAWindow::~GAWindow()
{
    delete ui;
}

void GAWindow::on_back_triggered()
{

}

void GAWindow::on_exit_triggered()
{

}

void GAWindow::on_about_triggered()
{

}
