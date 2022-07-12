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
   return true;
}
bool Model::setTaskParametrsFile(QString path){
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    QTextStream in(&file);
    if(in.atEnd()){
        file.close();
        return false;
    }
    QString line = in.readLine();
    if(in.atEnd()){
        file.close();
        return false;
    }
    QString line2 = in.readLine();
    int capacity = line.toInt(), quantity = line2.toInt();
    if((capacity < 4 || capacity >= 100) || (quantity < 3 || quantity >= 100)){
        file.close();
        return false;
    }
    data->setCapacity(capacity);
    std::vector<std::pair<unsigned int, unsigned int>> itemsGA;
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList str = line.split(' ');
        if(str.size() != 2){
            file.close();
            return false;
        }
        int coast = str[0].toInt(), weight = str[1].toInt();
        if(coast <= 0 || weight <= 0){
            file.close();
            return false;
        }
        itemsGA.push_back(std::make_pair<unsigned int, unsigned int>(coast, weight));
    }
    file.close();
    if(itemsGA.size()!= quantity)
        return false;
    return true;
}

bool Model::setGAParametrs(unsigned int population, unsigned int selectQuantity, float probability, std::pair<bool, unsigned int> seed, std::pair<unsigned int, unsigned int> typeEnd ){
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
    delete algorithm;
    delete data;
    data = new DataGA();
    algorithm = new ProblemSolve();
}

std::pair<bool,ViewData> Model::action(TypeStep step){
    if(step == TypeStep::next){
        return algorithm->nextStep();;
    }
    else if(step == TypeStep::prev){
        return algorithm->prevStep();;
    }
    else if(step == TypeStep::end){
        return algorithm->endSolution();
    }

}
