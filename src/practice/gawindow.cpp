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
    emit backToWindow();
}

void GAWindow::on_exit_triggered()
{
    qApp->exit();
}

void GAWindow::on_about_triggered()
{

}

void GAWindow::on_prevStep_clicked()
{
    emit toBack();
}

void GAWindow::on_nextStep_clicked()
{
    emit toNext();
}

void GAWindow::on_solution_clicked()
{
    emit toSolution();
}
