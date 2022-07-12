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
        if(allPopulation.size() >= data->getQuantityPopulationEnd()){
            for(int i = currentStep; i >= currentStep-data->getQuantityPopulationEnd(); i--){
                if(allPopulation[i].maxFitnes.first != allPopulation[currentStep].maxFitnes.first ){
                    return false;
                }
            }
            return true;
        }
        else{
            return true;
        }
    }
    return false;
}

std::pair<bool,ViewData>  ProblemSolve::nextStep(){
    if(currentStep != allPopulation.size()){
        currentStep++;
        return std::make_pair(true, allPopulation[currentStep-1]);
    }else{
        if(!isEnd()){
            ViewData curPopulation;
            curPopulation.maxFitnes = ga->maxFitnes();
            curPopulation.population = ga->getPopulation();
            ga->selection();
            curPopulation.crossing = ga->crossing();
            curPopulation.mutations = ga->mutation();
            curPopulation.child = ga->getChild();
            currentStep++;
            ga->transfer();
            curPopulation.step = currentStep;
            allPopulation.push_back(curPopulation);
            return std::make_pair(true, allPopulation[currentStep-1]);
        }

    }
    return std::make_pair(false,allPopulation[allPopulation.size()-1]);
}

std::pair<bool,ViewData> ProblemSolve::prevStep(){
    currentStep--;
    if(currentStep > 1){
        qDebug() << "1\n" << QString::number(currentStep-1);
        return std::make_pair(true, allPopulation[currentStep-1]);
    }
    else{

        return std::make_pair(false,allPopulation[currentStep]);
    }
}

std::pair<bool,ViewData> ProblemSolve::endSolution(){
    while(nextStep().first){}
    return std::make_pair(true, allPopulation[currentStep-1]);
}
