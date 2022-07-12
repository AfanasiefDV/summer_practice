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
    unsigned int quantityConstPopulation;
    unsigned int currentStep;
public:
    ProblemSolve();
    ~ProblemSolve();
    ProblemSolve(const DataGA* data);
    bool isEnd();
    std::pair<bool,ViewData> nextStep();
    std::pair<bool,ViewData>  prevStep();
    std::pair<bool,ViewData> endSolution();
    void init();

};

#endif // PROBMLENSOLVE_H
