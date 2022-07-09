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
    InputWindow *fileUI = new InputWindow();
    InputGuiWindow *graphicUI = new InputGuiWindow();
    ParametersWindow *parUI = new ParametersWindow();
    GAWindow *gaUI = new GAWindow();
    Presenter* presenter = new Presenter(view, fileUI, graphicUI, parUI, gaUI);

    Q_UNUSED(presenter);
    view->show();

    return a.exec();
}
