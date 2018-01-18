#include "element.h"

// element::element(): path() s{}

void element::addSlotAdress(int *item){
    path.push_back(item);
}

int* element::getDirection(){
    // int *minAdress;
    int minValue=10;
    int* minAdress=NULL;
    list<int*>::iterator it;
    it=path.begin();
    minAdress = *it;
    minValue=*(*it); //wielkosc kolejki na kotra wskazuje element w listze<int*>
    // it++; //zeby nie sprawdzac potem tego co juz przypisalismy do minimum czy jest minimum
    for(; it!=path.end(); it++){
        if((*(*it))<minValue){
            minAdress=*it;
            minValue=*(*it);
        }
    }//petla poszukuje najmniejszej(najkrotszej) kolejki
    if((minValue)>9)
        return(NULL);
    return(minAdress);
}
