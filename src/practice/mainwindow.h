#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void guiInput();
    void fileInput();
private slots:

    void on_guiInput_clicked();

    void on_fileInput_clicked();

    void on_exitApp_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
