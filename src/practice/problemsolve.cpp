#include "problemsolve.h"
#include <QDebug>
ProblemSolve::ProblemSolve():data(nullptr)
{
    quantityConstPopulation = 0;
    currentStep = 0;
}
ProblemSolve::ProblemSolve(const DataGA* data): data(data), ga(new GA(data)) {
    quantityConstPopulation = 0;
    currentStep = 0;
}
ProblemSolve::~ProblemSolve(){

}

bool ProblemSolve::isEnd(){
    if(data->getTypeEnd() == typesEnd::Population){
        if(allPopulation.size() == data->getQuantityPopulationEnd()){
            return true;
        }
        return false;
    }
    else if(data->getTypeEnd() == typesEnd::constPopulation){
        return true;
    }
}

ViewData ProblemSolve::nextStep(){
    bool isCorrect = false;
    if(currentStep != allPopulation.size()){
        currentStep++;
        isCorrect = true;
    }else{
        if(!isEnd()){
            qDebug() << "1\n";
            ViewData curPopulation;
            qDebug() << "2\n";
            curPopulation.maxFitnes = ga->maxFitnes();
            qDebug() << "3\n";
            curPopulation.population = ga->getPopulation();
            qDebug() << "4\n";
            ga->selection();
            qDebug() << "5\n";
            curPopulation.crossing = ga->crossing();
            qDebug() << "6\n";
            curPopulation.mutations = ga->mutation();
            qDebug() << "7\n";
            curPopulation.child = ga->getChild();
            qDebug() << "8\n";
            currentStep++;
            ga->transfer();
            qDebug() << "9\n";
            isCorrect = true;
            qDebug() << "10\n";
            allPopulation.push_back(curPopulation);
        }

    }
    qDebug() << "next\n";
    return allPopulation[currentStep-1];
}

ViewData ProblemSolve::prevStep(){
    bool isCorrect = false;
    if(currentStep >= 0){
        currentStep--;
        isCorrect = true;

    }
    return allPopulation[currentStep];
}
void ProblemSolve::init(){

}

ViewData ProblemSolve::endSolution(){
    return allPopulation[currentStep];
}
