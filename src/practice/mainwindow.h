#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <inputwindow.h>
#include <inputguiwindow.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_guiInput_clicked();

    void on_fileInput_clicked();

    void on_exitApp_clicked();

private:
    InputWindow *fileUI;
    InputGuiWindow *graficUI;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
