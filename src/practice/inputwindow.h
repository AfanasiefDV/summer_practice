#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class InputWindow;
}

class InputWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InputWindow(QWidget *parent = 0);
    QString getFilePath();
    ~InputWindow();
signals:
    void backToWindow();
    void toParamWindow();
private slots:
    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

    void on_transtionPar2_clicked();

private:
    Ui::InputWindow *ui;
};

#endif // INPUTWINDOW_H


