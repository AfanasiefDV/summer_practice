#ifndef DATAGA_H
#define DATAGA_H
#include <vector>
#include <utility>
#include <ctime>

class DataGA
{
    std::vector<std::pair<unsigned int, unsigned int>> items;
    unsigned int sizePopulation, capacity;
    unsigned int seed;
public:
    DataGA();
    void setSizePopulation(unsigned int sizePopulation);
    void setCapacity(unsigned int capacity);
    void setSeed(unsigned int seed);
    void setItems(std::vector<std::pair<unsigned int, unsigned int>> items);

    const unsigned int getSizePopulation();
    const unsigned int getCapacity();
    const unsigned int getSeed();
    const std::vector<std::pair<unsigned int, unsigned int>> getItems();
};

#endif // DATAGA_H
