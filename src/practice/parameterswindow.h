#ifndef PARAMETERSWINDOW_H
#define PARAMETERSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ParametersWindow;
}

class ParametersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParametersWindow(QWidget *parent = 0);
    ~ParametersWindow();
signals:
    void backToWindow();
private slots:
    void on_transitonGA_clicked();

private:
    Ui::ParametersWindow *ui;
};

#endif // PARAMETERSWINDOW_H
