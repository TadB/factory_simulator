#include "element.h"


element::element(int number){
    interval = number;
}
void element::addSlotAdress(int *item){
    path.push_back(item);
}

int* element::getDirection(){
    int minValue=10;
    int* minAdress=NULL;
    list<int*>::iterator it;
    it=path.begin();
    minAdress = *it;
    minValue=*(*it); //wielkosc kolejki na kotra wskazuje element w listze<int*>
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

bool element::isMade(int number){
    int check;
    check = number%interval;
    if(check == 0)
        return true;
    else
        return false;
}
