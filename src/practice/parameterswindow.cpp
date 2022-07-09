#include "parameterswindow.h"
#include "ui_parameterswindow.h"

ParametersWindow::ParametersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParametersWindow)
{
    ui->setupUi(this);
}

ParametersWindow::~ParametersWindow()
{
    delete ui;
}

void ParametersWindow::on_transitonGA_clicked()
{

}

void ParametersWindow::on_back_triggered()
{

}

void ParametersWindow::on_exit_triggered()
{

}

void ParametersWindow::on_about_triggered()
{

}
