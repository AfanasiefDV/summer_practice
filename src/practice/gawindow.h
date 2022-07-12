#ifndef GAWINDOW_H
#define GAWINDOW_H
#include "datastruct.h"
#include <QMainWindow>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <vector>
namespace Ui {
class GAWindow;
}

class GAWindow : public QMainWindow
{
    Q_OBJECT
    QHBoxLayout *results;
    QVBoxLayout *population;
    std::vector<QLabel*> genes, genesChild;
    QVBoxLayout *child;
    bool flag =true;
public:
    explicit GAWindow(QWidget *parent = 0);
    ~GAWindow();
    void updateView(ViewData data);
    void blockPrev(bool isBlock);
    void blockNext(bool isBlock);
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
