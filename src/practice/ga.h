#ifndef GA_H
#define GA_H
#include <vector>
#include <utility>
#include <algorithm>

#include "chromosome.h"
#include "dataga.h"

class GA
{
    const DataGA* data;
    std::vector<Chromosome> population, child;
    std::vector<int> inSelection;
    void pick();
public:
    GA(const DataGA* data);
    GA();
    void selection();
    void mutation();
    void crossing();
    void transfer();
    std::vector<Chromosome> getPopulation();
    std::vector<Chromosome> getChild();
};

#endif // GA_H
