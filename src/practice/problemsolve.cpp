#include "problemsolve.h"

ProblemSolve::ProblemSolve():data(new DataGA())
{
    quantityConstPopulation = 0;
    currentStep = 0;
}
ProblemSolve::ProblemSolve(const DataGA* data): data(data), ga(new GA(data)) {
    quantityConstPopulation = 0;
    currentStep = 0;
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

void ProblemSolve::nextStep(){
    bool isCorrect = false;
    if(currentStep != allPopulation.size()){
        currentStep++;
        isCorrect = true;
    }else{
        if(isEnd()){
            ga->selection();
            ga->crossing();
            ga->mutation();
            allPopulation.push_back(std::make_pair(ga->getPopulation(), ga->getChild()));
            currentStep++;
            ga->transfer();
            isCorrect = true;
        }

    }

}

void ProblemSolve::prevStep(){
    bool isCorrect = false;
    if(currentStep >= 0){
        currentStep--;
        isCorrect = true;

    }

}

void ProblemSolve::endSolution(){

}
