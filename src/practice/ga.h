#ifndef GA_H
#define GA_H
#include <vector>
#include <utility>

#include "chromosome.h"

class GA
{

    std::vector<Chromosome> population, child;
public:
    GA();
};

#endif // GA_H
