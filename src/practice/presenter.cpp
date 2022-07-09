#include "presenter.h"
#include <QDebug>
Presenter::Presenter(MainWindow* view, InputWindow *fileUI, InputGuiWindow *graphicUI, ParametersWindow *parUI, GAWindow *gaUI, QObject *parent) :view(view), fileUI(fileUI), graphicUI(graphicUI), parUI(parUI), gaUI(gaUI),model(new Model()), QObject(parent)
{
    // main
    connect(view, SIGNAL(guiInput()), this, SLOT(transitGUIWindow()));
    connect(view, SIGNAL(fileInput()), this, SLOT(transitFileWindow()));

    //file
    connect(fileUI, SIGNAL(backToWindow()), this, SLOT(backMainWindow()));
    connect(fileUI, SIGNAL(toParamWindow()), this, SLOT(transitParWindow()));

    //gui
    connect(graphicUI, SIGNAL(backToWindow()), this, SLOT(backMainWindow()));
    connect(graphicUI, SIGNAL(toParamWindow()), this, SLOT(transitParWindow()));

    //par
    connect(parUI, SIGNAL(backToWindow()),this,SLOT(backMainWindow()));
    connect(parUI,  SIGNAL(toGAWindow()),this,SLOT(transitGAWindow()));

    //ga
    connect(gaUI, SIGNAL(backToWindow()), this, SLOT(backMainWindow()));
    connect(gaUI, SIGNAL(toBack()), this, SLOT(backStep()));
    connect(gaUI, SIGNAL(toNext()), this, SLOT(nextStep()));
    connect(gaUI, SIGNAL(toSolution()), this, SLOT(transitToSolution()));


}

Presenter::~Presenter(){
    delete model;
}

void Presenter::transitFileWindow(){
    view->close();
    fileUI->show();
}

void Presenter::transitGUIWindow(){
    view->close();
    graphicUI->show();
}

void Presenter::backMainWindow(){
    QMainWindow* sen = qobject_cast<QMainWindow*>(sender());
    sen->close();
    view->show();
}

void Presenter::transitParWindow(){
    bool isCorrect = false;
    if(graphicUI->isVisible()){
        isCorrect = model->setTaskParametrs(graphicUI->getCapacity(),graphicUI->getQuantityItems(),graphicUI->getItems());
    }

    if(isCorrect){
        QMainWindow* sen = qobject_cast<QMainWindow*>(sender());
        sen->close();
        parUI->show();
    }
}

void Presenter::transitGAWindow(){
    bool isCorrect = false;
    parUI->close();
    gaUI->show();
}

void Presenter::nextStep(){

}

void Presenter::backStep(){

}

void Presenter::transitToSolution(){

}
