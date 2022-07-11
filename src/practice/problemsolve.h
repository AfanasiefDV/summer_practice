#ifndef PROBMLENSOLVE_H
#define PROBMLENSOLVE_H
#include <vector>
#include "ga.h"
#include "dataga.h"
#include "datastruct.h"
#include "chromosome.h"

class ProblemSolve
{
    GA* ga;
    const DataGA* data;
    std::vector<ViewData> allPopulation;
    bool isEnd();
    unsigned int quantityConstPopulation;
    unsigned int currentStep;
public:
    ProblemSolve();
    ~ProblemSolve();
    ProblemSolve(const DataGA* data);
    ViewData nextStep();
    ViewData prevStep();
    ViewData endSolution();
    void init();

};

#endif // PROBMLENSOLVE_H
