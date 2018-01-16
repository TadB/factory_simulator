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

}
template<class A>
void factory::fillVector(vector<A> *item, int number){
    for(int i=0; i<number; i++){
        A temporary;
        (*item).push_back(temporary);
    }
}

void factory::runElements(vector<element> *elem){

}

void factory::runProducts(vector<product> *prod){

}
