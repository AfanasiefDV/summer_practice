#include "inputwindow.h"
#include "ui_inputwindow.h"

InputWindow::InputWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InputWindow)
{
    ui->setupUi(this);
}

InputWindow::~InputWindow()
{
    delete ui;
}
void InputWindow::on_back_triggered()
{
    emit backToWindow();
}

void InputWindow::on_exit_triggered()
{
    qApp->exit();
}

void InputWindow::on_about_triggered()
{

}

void InputWindow::on_transtionPar2_clicked()
{
    emit toParamWindow();
}
QString InputWindow::getFilePath(){
    return ui->fileEdit->text();
}
