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
    void toBack();
    void toNext();
    void toSolution();
private slots:
    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

    void on_prevStep_clicked();

    void on_nextStep_clicked();

    void on_solution_clicked();

private:
    Ui::GAWindow *ui;
};

#endif // GAWINDOW_H
