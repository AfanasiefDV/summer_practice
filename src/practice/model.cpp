#include "model.h"
#include <QDebug>
Model::Model():data(new DataGA()), algorithm(new ProblemSolve()){}
Model::~Model(){
    delete algorithm;
    delete data;
}

bool Model::setTaskParametrs(int capacity, int quantity, QString items){
    std::vector<std::pair<unsigned int, unsigned int>> itemsGA;
    data->setCapacity(capacity);
    QStringList list = items.split('\n');
    if(list.size() != quantity)
        return false;
    for(int i = 0; i < quantity; i++){
        QStringList str = list[i].split(' ');
        if(str.size() != 2)
            return false;
        int coast = str[0].toInt(), weight = str[1].toInt();
        if(coast <= 0 || weight <= 0)
            return false;
        itemsGA.push_back(std::make_pair<unsigned int, unsigned int>(coast, weight));
    }
   data->setItems(itemsGA);
   qDebug() << QString::number(itemsGA.size()) << "\n";

   return true;
}

bool Model::setGAParametrs(unsigned int population, unsigned int selectQuantity, float probability, std::pair<bool, unsigned int> seed, std::pair<unsigned int, unsigned int> typeEnd ){

    qDebug() << QString::number(data->getItems().size()) << "\n";
    if((population/2) < selectQuantity){
        return false;
    }
    data->setSizePopulation(population);
    data->setNumIndividualsSelection(selectQuantity);
    if(!seed.first){
        data->setSeed(seed.second);
    }
    data->setProbabilityMutation(probability);
    data->setQuantityPopulationEnd(typeEnd.second);
    data->setTypeEnd(typeEnd.first);
    return true;
}
void Model::setGA(){
    delete algorithm;
    algorithm = new ProblemSolve(data);
}
void Model::drop(){
    //delete algorithm;
    //delete data;
    //data = new DataGA();
    //algorithm = new ProblemSolve();
}

ViewData Model::action(TypeStep step){
    qDebug() << "model\n";
    if(step == TypeStep::next){
        ViewData a = algorithm->nextStep();
        qDebug() << "model ret\n";
        return a;
    }
}
