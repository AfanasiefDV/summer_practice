#include "gawindow.h"
#include "ui_gawindow.h"
#include <QDebug>

GAWindow::GAWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GAWindow)
{
    ui->setupUi(this);
    results = new QHBoxLayout();
    population = new QVBoxLayout();
    child = new QVBoxLayout();
}

GAWindow::~GAWindow()
{
    delete ui;
}

void GAWindow::updateView(ViewData data){
    QString info;
    //info += QString::number(data.population.size()) + QString::number(data.child.size());
    info += "Шаг "+QString::number(data.step) + "\n";
    info += "Макисмальная фитнес функция: " + QString::number(data.maxFitnes.first)+"\n";
    info += "У особей:\n";
    for(int i = 0; i < data.maxFitnes.second.size(); i++){
        info += QString::number(data.maxFitnes.second[i])+"\n";
    }
    info += "Был проведен кросииногвер между особями:\n";
    for(int i = 0; i < data.crossing.size(); i++){
        info += QString::number(data.crossing[i].first)+" и " + QString::number(data.crossing[i].second)+"\n";
    }
    info += "Мутировали особи: ";
    for(int i = 0; i < data.mutations.size(); i++){
        info += QString::number(data.mutations[i].first)+" ген " + QString::number(data.mutations[i].second)+"\n";
    }
    ui->mainInformation->setText(info);

    //if(ui->scrollAreaWidgetContents)
       // delete ui->scrollAreaWidgetContents;
    //ui->scrollAreaWidgetContents = new QWidget(ui->scrollArea);

    /*
2 1
3 2
4 4


    if(results){
        qDebug() << "delete\n";
        delete results;
    }
    results = new QHBoxLayout();

    */
    if(flag){

        population->addWidget(new QLabel(QString("Популяция")));
        child->addWidget(new QLabel(QString("Потомство")));

        for(int i = 0; i < data.population.size(); i++){
            genes.push_back(new QLabel(data.population[i].getStr()));
            population->addWidget(genes[i]);
            genesChild.push_back(new QLabel(data.child[i].getStr()));
            child->addWidget(genesChild[i]);
        }
        results->addLayout(population);
        results->addLayout(child);
        ui->scrollAreaWidgetContents->setLayout(results);
        flag = false;
    }
    else{
        for(int i = 0; i < data.population.size(); i++){
            genes[i]->setText(data.population[i].getStr());
            genesChild[i]->setText(data.child[i].getStr());
        }
    }

}

void GAWindow::on_back_triggered()
{
    emit backToWindow();
}

void GAWindow::on_exit_triggered()
{
    qApp->exit();
}

void GAWindow::on_about_triggered()
{

}

void GAWindow::on_prevStep_clicked()
{
    emit toBack();
}

void GAWindow::on_nextStep_clicked()
{
    emit toNext();
}

void GAWindow::on_solution_clicked()
{
    emit toSolution();
}
void GAWindow::blockPrev(bool isBlock){
    ui->prevStep->setHidden(isBlock);

}
void GAWindow::blockNext(bool isBlock){
    ui->nextStep->setHidden(isBlock);
    ui->solution->setHidden(isBlock);

}
