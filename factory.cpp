#include "factory.h"

//konstruktory
factory::factory(){
    cout<<"nie ma pustych fabryk!";
    exit(0);
}

factory::factory(int tableNo, int lockerNo, int legNo, int desktopNo, int doorNo, int casingNo){
    if((tableNo==0) ||(lockerNo==0) ||(legNo==0) ||(desktopNo==0) ||(doorNo==0) ||(casingNo==0)){
        cout<<"fabryka jest niepelna nie mozna tak produkowac"<<endl;
        exit(0);
    }
//{{{ uzupelnianie vectorow zadana liczba stanowisk
    fillVector(&table, tableNo);
    fillVector(&locker, lockerNo);
    fillVector(&leg, legNo);
    fillVector(&desktop, desktopNo);
    fillVector(&door, doorNo);
    fillVector(&casing, casingNo);
//}}}
}

void factory::run(){
//{{{przekazujemy polprodukty do stacji montazowych
    runElement(&leg);
    runElement(&desktop);
    runElement(&door);
    runElement(&casing);
//}}}
//{{{ powiekszamy magazyny
    storehouseTable+=runProduct(&table);
    storehouseLocker+=runProduct(&locker);
//}}}
}

void factory::runElement(vector<element> *elem){
    vector<element>::iterator it;
    int *index; //wskaznik na kolejke ktora jest najkrotsza - do niej wysylamy podzespol
    for(it=(*elem).begin(); it<(*elem).end(); it++){
        if((*it).getDirection()!=NULL){
            index=(*it).getDirection();
            (*index)++;
        }//jesli getDirection() zwroci NULL to znaczy ze kolejka jest przepelniona i stanowisko musi poczekac
    }
}

int factory::runProduct(vector<product> *prod){
    int howMany=0; //jak wiele produktow wyprodukuje zbior(vector)(tych samych) stanowisk
    vector<product>::iterator it;
    for(it=(*prod).begin(); it<(*prod).end(); it++){
        if((*it).result()==true)
            howMany++;
    }
    return(howMany);
}

template<class A>
void factory::fillVector(vector<A> *item, int number){
    for(int i=0; i<number; i++){
        A temporary;
        (*item).push_back(temporary);
    }
}
