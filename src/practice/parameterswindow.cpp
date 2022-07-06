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
