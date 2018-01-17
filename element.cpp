#include "element.h"

// element::element(): path() s{}

void element::addSlotAdress(int *item){
    path.push_back(item);
}

int* element::getDirection(){
    // int *minAdress;
    int minValue=10, i=0;
    int* minAdress=NULL;
    vector<int*>::iterator it;
    it=path.begin();
    minAdress = path[i];
    minValue=*(path[i]); //wielkosc kolejki na kotra wskazuje element w vectorze<int*>
    // it++; //zeby nie sprawdzac potem tego co juz przypisalismy do minimum czy jest minimum
    for(i=0; it<path.end(); i++,it++){
        if((*(path[i]))<minValue){
            minAdress=path[i];
            minValue=*(path[i]);
        }
    }//petla poszukuje najmniejszej(najkrotszej) kolejki
    if((minValue)>9)
        return(NULL);
    return(minAdress);
}
