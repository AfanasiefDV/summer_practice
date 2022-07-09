#ifndef MODEL_H
#define MODEL_H
#include "ga.h"
#include "dataga.h"
#include<QString>
#include<QStringList>
#include <vector>
#include <utility>
class Model
{
    DataGA data;
    GA algorithm;
public:
    Model();
    ~Model();
    bool setTaskParametrs(int capacity, int quantity, QString items);
    bool setGAParametrs(int capacity, int quantity, QString items);

};

#endif // MODEL_H
