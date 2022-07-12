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
    this->capacity = capacity;
}

void DataGA::setSeed(unsigned int seed){
    this->seed =seed;
}

void DataGA::setNumIndividualsSelection(unsigned int numIndividualsSelection){
    this->numIndividualsSelection = numIndividualsSelection;
}

void DataGA::setProbabilityMutation(float probabilityMutation){
    this->probabilityMutation = probabilityMutation;
}

void DataGA::setItems(std::vector<std::pair<unsigned int, unsigned int>> items){
    this->items = items;
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

void DataGA::setQuantityPopulationEnd(unsigned int quantity){
    quantityPopulationEnd = quantity;
}

void DataGA::setTypeEnd(int type){
    if(type){
        ends = typesEnd::constPopulation;
    }else{
        ends = typesEnd::Population;
    }
}

unsigned int DataGA::getQuantityPopulationEnd() const{
    return quantityPopulationEnd;
}
typesEnd DataGA::getTypeEnd() const{
    return ends;
}
