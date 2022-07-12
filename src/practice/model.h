#ifndef MODEL_H
#define MODEL_H
#include "ga.h"
#include "dataga.h"
#include "problemsolve.h"
#include "datastruct.h"
#include<QString>
#include<QStringList>
#include <vector>
#include <utility>
#include <QTextStream>
#include <QFile>

enum TypeStep{
    next,
    prev,
    end
};


class Model
{
    DataGA* data;
    ProblemSolve* algorithm;

public:

    Model();
    ~Model();
    bool setTaskParametrs(int capacity, int quantity, QString items);
    bool setGAParametrs(unsigned int population, unsigned int selectQuantity, float probability, std::pair<bool, unsigned int> seed, std::pair<unsigned int, unsigned int> typeEnd );
    bool setTaskParametrsFile(QString path);
    void setGA();
    void drop();
    std::pair<bool,ViewData> action(TypeStep step);
};

#endif // MODEL_H
