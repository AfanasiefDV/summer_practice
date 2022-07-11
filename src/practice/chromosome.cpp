#include "chromosome.h"
#include <QDebug>
#include <QString>
Chromosome::Chromosome(const DataGA* data) : data(data)
{
    for(int i = 0; i < data->getItems().size(); i++ )
        genes.push_back(rand()%2);
    this->correction();
}

Chromosome::Chromosome(const DataGA* data, std::vector<bool> parent1, std::vector<bool> parent2): data(data){
    for(int i = 0; i < parent1.size()/2; i++){
        genes.push_back(parent1[i]);
    }
    for(int i = parent2.size()/2; i < parent2.size(); i++){
        genes.push_back(parent2[i]);
    }
    this->correction();

}

unsigned int Chromosome::fitnessFunction(){
    unsigned int value = 0;
    const std::vector<std::pair<unsigned int, unsigned int>>& items = data->getItems();
    for(int i = 0; i < items.size(); i++)
        value += genes[i]*items[i].first;
    return value;
}

void Chromosome::correction(){

    while(!isAcceptable()){
        int randValue = rand()%genes.size();
        genes[randValue] = 0;
    }
}

int Chromosome::mutation(){
    int randValue = -1;
    qDebug() << "er1\n";
    if(rand()%101 < data->getProbabilityMutation()*100){

        qDebug() << "er2 \n" << genes.size();
        int a = rand()%genes.size();
        qDebug() << "a\n" << a;
        randValue = a;
        qDebug() << genes.size() << " " << randValue << "\n";
        genes[randValue] = !genes[randValue];

        qDebug() << "er3\n";
        correction();
    }
    return randValue;
}

bool Chromosome::isAcceptable(){
    unsigned int value = 0;
    const std::vector<std::pair<unsigned int, unsigned int>>& items = data->getItems();
    for(int i = 0; i < items.size(); i++)
        value += genes[i]*items[i].second;
    return value <= data->getCapacity();
}
std::vector<bool> Chromosome::getGenes(){
    return genes;
}
