#include "parameterswindow.h"
#include "ui_parameterswindow.h"

ParametersWindow::ParametersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParametersWindow)
{
    ui->setupUi(this);
    ui->quantityPopulation->setChecked(true);
}

ParametersWindow::~ParametersWindow()
{
    delete ui;
}

void ParametersWindow::on_transitonGA_clicked()
{
    emit toGAWindow();
}

void ParametersWindow::on_back_triggered()
{
    emit backToWindow();
}

void ParametersWindow::on_exit_triggered()
{
    qApp->exit();
}

void ParametersWindow::on_about_triggered()
{

}

int ParametersWindow::getPopulation(){
    return ui->populationBox->value();
}

int ParametersWindow::getSelectionQuantity(){
    return ui->quantityBox->value();
}

int ParametersWindow::getSeed(){
    return ui->seedBox->value();
}

float ParametersWindow::getProbabilty(){
    return ui->ProbabilityBox->value();
}

void ParametersWindow::on_quantityPopulation_clicked()
{
    ui->quantityConstPopulation->setChecked(false);
}

void ParametersWindow::on_quantityConstPopulation_clicked()
{
    ui->quantityPopulation->setChecked(false);
}
