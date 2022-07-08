#ifndef GAWINDOW_H
#define GAWINDOW_H

#include <QMainWindow>

namespace Ui {
class GAWindow;
}

class GAWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GAWindow(QWidget *parent = 0);
    ~GAWindow();
signals:
    void backToWindow();
private slots:
    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

private:
    Ui::GAWindow *ui;
};

#endif // GAWINDOW_H
