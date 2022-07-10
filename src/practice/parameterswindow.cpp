#include "parameterswindow.h"
#include "ui_parameterswindow.h"
#include <QDebug>
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

std::pair<bool, unsigned int>  ParametersWindow::getSeed(){
    return std::make_pair(ui->defaultSeed->isChecked(), ui->seedBox->value());
}

float ParametersWindow::getProbabilty(){
    return ui->ProbabilityBox->value();
}

std::pair<unsigned int, unsigned int> ParametersWindow::getTypeEnd(){
    int type = 0;
    if(ui->quantityConstPopulation->isChecked()){
        type++;
    }

    return std::make_pair(type, ui->endValue->value());
}

void ParametersWindow::on_quantityPopulation_clicked()
{
    ui->quantityConstPopulation->setChecked(false);
}

void ParametersWindow::on_quantityConstPopulation_clicked()
{
    ui->quantityPopulation->setChecked(false);
}

void ParametersWindow::on_defaultSeed_clicked()
{
    if(ui->defaultSeed->isChecked()){
        ui->seedBox->setHidden(true);
    }
    else{
        ui->seedBox->setHidden(false);
    }
}
