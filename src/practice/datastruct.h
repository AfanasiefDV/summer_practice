#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <vector>

struct ViewData{
    std::vector<bool>& population, child;
    std::vector<std::pair<unsigned int, unsigned int>> mutations;
    std::vector<unsigned int> maxFitnes;
    unsigned int maxFitnesValue;
    unsigned int currentStep;
};

#endif // DATASTRUCT_H
