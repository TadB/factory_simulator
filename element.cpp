#include "element.h"

// element::element(): path() s{}

void element::addSlotAdress(int *item){
    path.push_back(item);
}

int* element::getDirection(){
    // int *minAdress;
    int minValue=10;
    vector<int*>::iterator it=path.begin();
    int* minAdress = path.at(0);
    minValue=*(path.at(0)); //wielkosc kolejki na kotra wskazuje element w vectorze<int*>
    it++; //zeby nie sprawdzac potem tego co juz przypisalismy do minimum czy jest minimum
    for(int i=1; it<path.end(); i++,it++){
        if(*(path.at(i))<minValue){
            minAdress=path.at(i);
            minValue=*(path.at(i));
        }
    }//petla poszukuje najmniejszej(najkrotszej) kolejki
    if((minValue)>9)
        return(NULL);
    return(minAdress);
}
