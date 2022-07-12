#include "ga.h"
#include <QDebug>
GA::GA(){}
GA::GA(const DataGA* data) : data(data){
    for(int i = 0; i < data->getSizePopulation(); i++)
        population.push_back(Chromosome(data));
}

void GA::selection(){
    inSelection.clear();
    for(int i = 0; i < data->getSizePopulation(); i++){
        pick();
    }
}

void GA::pick(){
    unsigned int index = 0,  maxFitness = 0;
    for(int i = 0; i < data->getSizePopulation(); i++){
        unsigned int newIndex = rand()%data->getSizePopulation();
        unsigned int newMaxFitness = population[newIndex].fitnessFunction();
        if(newMaxFitness > maxFitness){
            index = newIndex;
            maxFitness = population[newIndex].fitnessFunction();
        }
    }
    inSelection.push_back(index);
}

std::vector<std::pair<unsigned int, unsigned int>> GA::mutation(){
    std::vector<std::pair<unsigned int, unsigned int>> vec;
    for(int i = 0; i < child.size(); i++){
        int value = child[i].mutation();
        if(value >= 0){
            vec.push_back(std::make_pair(i, value));
        }
    }
    return vec;
}

std::vector<std::pair<unsigned int, unsigned int>> GA::crossing(){
    std::vector<std::pair<unsigned int, unsigned int>> vec;
    while(2*vec.size() != data->getSizePopulation()){
        int i = rand()%inSelection.size();
        int j = rand()%inSelection.size();
        if(i != j){
            child.push_back(Chromosome(data, population[inSelection[i]].getGenes(),population[inSelection[j]].getGenes()));
            child.push_back(Chromosome(data, population[inSelection[j]].getGenes(),population[inSelection[i]].getGenes()));
            vec.push_back(std::make_pair(inSelection[i], inSelection[j]));
        }
    }
    return vec;
}

void GA::transfer(){
    population = child;
    child.clear();
    inSelection.clear();

}

std::vector<Chromosome> GA::getPopulation(){
    return population;
}

std::vector<Chromosome> GA::getChild(){
    return child;
}

std::pair<unsigned int, std::vector<unsigned int>> GA::maxFitnes(){
    unsigned int max = 0;
    std::vector<unsigned int> index;
    for(int i = 0; i < population.size();i++){
        unsigned int fitnes = population[i].fitnessFunction();
        if(max < fitnes){
            max = fitnes;
            index.clear();
            index.push_back(i);
        }
        else if(max == fitnes){
            index.push_back(i);
        }
    }
    return std::make_pair(max, index);
}
