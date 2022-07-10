#ifndef PROBMLENSOLVE_H
#define PROBMLENSOLVE_H
#include <vector>
#include "ga.h"
#include "dataga.h"
#include "chromosome.h"

class ProblemSolve
{
    std::vector<std::pair<std::vector<Chromosome>,std::vector<Chromosome>>> allPopulation;
    GA* ga;
    const DataGA* data;
    bool isEnd();
    unsigned int quantityConstPopulation;
    unsigned int currentStep;
public:
    ProblemSolve();
    ProblemSolve(const DataGA* data);
    void nextStep();
    void prevStep();
    void endSolution();

};

#endif // PROBMLENSOLVE_H
