#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include "mainwindow.h"
#include "inputwindow.h"
#include "inputguiwindow.h"
#include "parameterswindow.h"
#include "gawindow.h"
#include "model.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(MainWindow* view, InputWindow *fileUI, InputGuiWindow *graphicUI, ParametersWindow *parUI, GAWindow *gaUI, QObject *parent = 0);
    ~Presenter();
private:
    MainWindow* view;
    Model *model;
    InputWindow *fileUI;
    InputGuiWindow *graphicUI;
    ParametersWindow *parUI;
    GAWindow *gaUI;
signals:

public slots:
};

#endif // PRESENTER_H
