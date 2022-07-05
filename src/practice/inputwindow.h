#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class InputWindow;
}

class InputWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputWindow(QWidget *parent = 0);
    ~InputWindow();
signals:
    void backToWindow();

private slots:
    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

private:
    Ui::InputWindow *ui;
};

#endif // INPUTWINDOW_H


