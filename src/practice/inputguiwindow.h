#ifndef INPUTGUIWINDOW_H
#define INPUTGUIWINDOW_H

#include <QMainWindow>

namespace Ui {
class InputGuiWindow;
}

class InputGuiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputGuiWindow(QWidget *parent = 0);
    ~InputGuiWindow();
signals:
    void backToWindow();
    void toParamWindow();

private slots:
    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

    void on_transtionPar1_clicked();

private:
    Ui::InputGuiWindow *ui;
};

#endif // INPUTGUIWINDOW_H
