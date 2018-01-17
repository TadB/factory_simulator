#include "factory.h"

//konstruktory
factory::factory(){
    cout<<"nie ma pustych fabryk!";
    exit(0);
}

factory::factory(int tableNo, int lockerNo, int legNo, int desktopNo, int doorNo, int casingNo){
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
//{{{ powiekszamy magazyny
    storehouseTable+=runProduct(&table);
    storehouseLocker+=runProduct(&locker);
//}}}
}
template<class A>
void factory::fillVector(vector<A> *item, int number){
    for(int i=0; i<number; i++){
        A temporary;
        (*item).push_back(temporary);
    }
}

void factory::runElement(vector<element> *elem){
    vector<element>::iterator it;
    queue<int> *index; //wskaznik na kolejke ktora jest najkrotsza - do niej wysylamy podzespol
    for(it=(*elem).begin(); it<(*elem).end(); it++){
        index=(*it).getDirection();
        (*index).push(1);
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
