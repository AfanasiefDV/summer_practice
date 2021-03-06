#ifndef DATAGA_H
#define DATAGA_H
#include <vector>
#include <utility>
#include <ctime>
#include <cstdlib>
enum typesEnd{
    constPopulation,
    Population
};


class DataGA
{
    std::vector<std::pair<unsigned int, unsigned int>> items;
    unsigned int sizePopulation, capacity;
    unsigned int seed, numIndividualsSelection;
    float probabilityMutation;
    unsigned int quantityPopulationEnd;
    typesEnd ends;
public:
    DataGA();
    void setSizePopulation(unsigned int sizePopulation);
    void setCapacity(unsigned int capacity);
    void setSeed(unsigned int seed);
    void setNumIndividualsSelection(unsigned int numIndividualsSelection);
    void setProbabilityMutation(float probabilityMutation);
    void setItems(std::vector<std::pair<unsigned int, unsigned int>> items);
    void setQuantityPopulationEnd(unsigned int quantity);
    void setTypeEnd(int type);
    unsigned int getSizePopulation() const;
    unsigned int getCapacity() const;
    unsigned int getSeed() const;
    unsigned int getNumIndividualsSelection() const;
    float getProbabilityMutation() const;
    const std::vector<std::pair<unsigned int, unsigned int>>& getItems() const;
    unsigned int getQuantityPopulationEnd() const;
    typesEnd getTypeEnd() const;
};

#endif // DATAGA_H
