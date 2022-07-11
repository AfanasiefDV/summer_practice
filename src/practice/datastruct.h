#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <vector>
#include <utility>
#include "chromosome.h"
struct ViewData{
    std::vector<Chromosome> population, child;
    std::vector<std::pair<unsigned int, unsigned int>> mutations;
    std::pair<unsigned int, std::vector<unsigned int>>  maxFitnes;
    std::vector<std::pair<unsigned int, unsigned int>> crossing;
};

#endif // DATASTRUCT_H
