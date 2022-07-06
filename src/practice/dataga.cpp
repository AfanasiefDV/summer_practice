#include "dataga.h"

DataGA::DataGA()
{
    seed = std::time(nullptr);
    std::srand(seed);
}

void DataGA::setSizePopulation(unsigned int sizePopulation){
    this->sizePopulation = sizePopulation;
}

void DataGA::setCapacity(unsigned int capacity){
    this->capacity;
}

void DataGA::setSeed(unsigned int seed){
    this->seed;
}

void DataGA::setNumIndividualsSelection(unsigned int numIndividualsSelection){
    this->numIndividualsSelection = numIndividualsSelection;
}

void DataGA::setProbabilityMutation(float probabilityMutation){
    this->probabilityMutation = probabilityMutation;
}

void DataGA::setItems(std::vector<std::pair<unsigned int, unsigned int>> items){
    this->items;
}

unsigned int DataGA::getSizePopulation() const{
    return this->sizePopulation;
}

unsigned int DataGA::getCapacity() const{
    return this->capacity;
}

unsigned int DataGA::getSeed() const{
    return this->seed;
}

unsigned int DataGA::getNumIndividualsSelection() const{
    return this->numIndividualsSelection;
}

float DataGA::getProbabilityMutation() const{
    return this->probabilityMutation;
}

const std::vector<std::pair<unsigned int, unsigned int>>& DataGA::getItems() const{
    return this->items;
}
