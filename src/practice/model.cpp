#include "model.h"

Model::Model(){}
Model::~Model(){

}

bool Model::setTaskParametrs(int capacity, int quantity, QString items){
    std::vector<std::pair<unsigned int, unsigned int>> itemsGA;
    data.setCapacity(capacity);
    QStringList list = items.split('\n');
    if(list.size() != quantity)
        return false;
    for(int i = 0; i < quantity; i++){
        QStringList str = list[i].split(' ');
        if(str.size() != 2)
            return false;
        int coast = str[0].toInt(), weight = str[1].toInt();
        if(coast <=0 || weight <= 0)
            return false;
        itemsGA.push_back(std::make_pair<unsigned int, unsigned int>(coast, weight));
    }
   data.setItems(itemsGA);
   return true;
}
