#ifndef PARAMETERSWINDOW_H
#define PARAMETERSWINDOW_H

#include <QMainWindow>
#include <utility>
namespace Ui {
class ParametersWindow;
}

class ParametersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParametersWindow(QWidget *parent = 0);
    ~ParametersWindow();
    int getPopulation();
    int getSelectionQuantity();
    std::pair<bool, unsigned int> getSeed();
    float getProbabilty();
    std::pair<unsigned int, unsigned int> getTypeEnd();

signals:
    void backToWindow();
    void toGAWindow();
private slots:
    void on_transitonGA_clicked();

    void on_back_triggered();

    void on_exit_triggered();

    void on_about_triggered();

    void on_quantityPopulation_clicked();

    void on_quantityConstPopulation_clicked();

    void on_defaultSeed_clicked();

private:
    Ui::ParametersWindow *ui;
};

#endif // PARAMETERSWINDOW_H
