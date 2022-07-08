#include "mainwindow.h"
#include "presenter.h"
#include "inputwindow.h"
#include "inputguiwindow.h"
#include "parameterswindow.h"
#include "gawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* view = new MainWindow();
    InputWindow *fileUI;
    InputGuiWindow *graphicUI;
    ParametersWindow *parUI;
    GAWindow *gaUI;
    Presenter* presenter = new Presenter(view, fileUI, graphicUI, parUI, gaUI);

    Q_UNUSED(presenter);
    view->show();


    delete fileUI;
    delete graphicUI;
    delete parUI;
    delete gaUI;
    delete ui;
    delete presenter;
    return a.exec();
}
