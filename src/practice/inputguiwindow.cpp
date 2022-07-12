#include "inputguiwindow.h"
#include "ui_inputguiwindow.h"

InputGuiWindow::InputGuiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InputGuiWindow)
{
    ui->setupUi(this);
}

InputGuiWindow::~InputGuiWindow()
{
    delete ui;
}

void InputGuiWindow::on_back_triggered()
{
    emit backToWindow();
}

void InputGuiWindow::on_exit_triggered()
{
    qApp->exit();
}

void InputGuiWindow::on_about_triggered()
{

}

void InputGuiWindow::on_transtionPar1_clicked()
{
    emit toParamWindow();
}

int InputGuiWindow::getCapacity(){
    return ui->CapacityBox->value();
}

int InputGuiWindow::getQuantityItems(){
    return ui->quantityItemsBox->value();
}

QString InputGuiWindow::getItems(){
    return ui->ItemsBox->toPlainText();
}

