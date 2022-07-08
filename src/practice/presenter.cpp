#include "presenter.h"

Presenter::Presenter(MainWindow* view, InputWindow *fileUI, InputGuiWindow *graphicUI, ParametersWindow *parUI, GAWindow *gaUI, QObject *parent) :view(view), fileUI(fileUI), graphicUI(graphicUI), parUI(parUI), gaUI(gaUI),model(new Model()), QObject(parent)
{
    // main
    connect
    //file

    //gui

    //par

    //ga

}

Presenter::~Presenter(){
    delete model;
}
