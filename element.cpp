#include "element.h"

void element::addSlotAdress(queue<int> *item){
    path.push_back(item);
}

queue<int>* element::getDirection(){
    // queue<int> *minAdress;
    unsigned int minValue;
    vector<queue<int>*>::iterator it=path.begin();
    queue<int> *minAdress = *it;
    minValue=(*it)->size();
    it++; //zeby nie sprawdzac potem tego co juz przypisalismy do minimum czy jest minimum
    for(; it<path.end(); it++){
        if(((*it)->size())<minValue){
            minAdress=*it;
            minValue=(*it)->size();
        }
    }//petla poszukuje najmniejszej(najkrotszej) kolejki
    return(minAdress);
}
