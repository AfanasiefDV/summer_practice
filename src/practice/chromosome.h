#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include "dataga.h"
class Chromosome
{
    const DataGA* data;
    std::vector<bool> genes;
    int indexMutation = -1;
public:
    Chromosome(const DataGA* data);
    Chromosome(const DataGA* data, std::vector<bool> parent1, std::vector<bool> parent2);
    unsigned int fitnessFunction();
    void correction();
    int mutation();
    bool isAcceptable();
    std::vector<bool> getGenes();
};

#endif // CHROMOSOME_H
