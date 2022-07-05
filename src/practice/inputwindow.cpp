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
    this->close();
    emit backToWindow();
}

void InputWindow::on_exit_triggered()
{
    qApp->exit();
}

void InputWindow::on_about_triggered()
{

}
