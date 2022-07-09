#include "ga.h"

GA::GA(){}
GA::GA(const DataGA data) : data(data){
    for(int i = 0; i < data.getSizePopulation(); i++)
        population.push_back(Chromosome(data));
}

void GA::selection(){
    inSelection.clear();
    for(int i = 0; i < data.getSizePopulation(); i++){
        pick();
    }
}

void GA::pick(){
    unsigned int index = 0,  maxFitness = 0;
    for(int i = 0; i < data.getSizePopulation(); i++){
        unsigned int newIndex = rand()%data.getSizePopulation();
        unsigned int newMaxFitness = population[newIndex].fitnessFunction();
        if(newMaxFitness > maxFitness){
            index = newIndex;
            maxFitness = population[newIndex].fitnessFunction();
        }
    }
    inSelection.push_back(index);
}

void GA::mutation(){
    for(int i = 0; i < data.getSizePopulation(); i++)
        child[i].mutation();
}

void GA::crossing(){
    while(!inSelection.empty()){
        int i = rand()%inSelection.size();
        int j = rand()%inSelection.size();
        child.push_back(Chromosome(data, population[inSelection[i]].getGenes(),population[inSelection[j]].getGenes()));
        child.push_back(Chromosome(data, population[inSelection[j]].getGenes(),population[inSelection[i]].getGenes()));
        if(i == j)
            inSelection.erase(inSelection.begin()+i);
        else{
            inSelection.erase(inSelection.begin()+i);
            inSelection.erase(inSelection.begin()+j);
        }
    }
}

void GA::transfer(){
    population = std::move(child);
    child.clear();
    inSelection.clear();

}
