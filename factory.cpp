#include "factory.h"

//konstruktory
factory::factory(){
    cout<<"nie ma pustych fabryk!";
    exit(0);
}

factory::factory(int tableNo, int lockerNo, int legNo, int desktopNo, int doorNo, int casingNo):storehouseTable(0), storehouseLocker(0){
    if((tableNo==0) ||(lockerNo==0) ||(legNo==0) ||(desktopNo==0) ||(doorNo==0) ||(casingNo==0)){
        cout<<"fabryka jest niepelna nie mozna tak produkowac"<<endl;
        exit(0);
    }
//{{{ uzupelnianie vectorow zadana liczba stanowisk
    fillVector(table, tableNo);
    fillVector(locker, lockerNo);
    fillVector(leg, legNo);
    fillVector(desktop, desktopNo);
    fillVector(door, doorNo);
    fillVector(casing, casingNo);
    makeGraph(leg, table);
    makeGraph(leg, locker);
    makeGraph(desktop, table);
    makeGraph(door, locker);
    makeGraph(casing, locker);


//}}}
}
void factory::makeGraph(vector<element> &source, vector<product> &dest){
    vector<element>::iterator it;
    vector<product>::iterator m;

    int i=0 ,j=0;
    for(j=0, m=dest.begin(); m<dest.end(); m++, j++){
        int *temp;
        temp=dest[j].addQueue();
        for(i=0, it=source.begin(); it<source.end(); it++, i++){
            source[i].addSlotAdress(temp);
        } //w tej petli lacze stanowiska robiace podprodukty z adresami stanowiski skladajacych meble
    }
}
void factory::run(){
//{{{przekazujemy polprodukty do stacji montazowych
    runElement(leg);
    runElement(desktop);
    runElement(door);
    runElement(casing);
//}}}
//{{{ powiekszamy magazyny
    int count=0;
    count = runProduct(table);
    storehouseTable+=count;
    count = runProduct(locker);
    storehouseLocker+=count;
//}}}
}
void factory::printRes(){
    cout<<"stolow wyprodukowano: "<<storehouseTable<<endl;
    cout<<"szafek wyprodukowano: "<<storehouseLocker<<endl;
}
void factory::runElement(vector<element> &elem){
    vector<element>::iterator it;
    int i;
    int *index; //wskaznik na kolejke ktora jest najkrotsza - do niej wysylamy podzespol
    for(i=0, it=elem.begin(); it<elem.end(); i++, it++){
        if((elem[i]).getDirection()!=NULL){
            index=(elem[i]).getDirection();
            (*index)++;
        }//jesli getDirection() zwroci NULL to znaczy ze kolejka jest przepelniona i stanowisko musi poczekac
    }
}

int factory::runProduct(vector<product> &prod){
    int i, howMany=0; //jak wiele produktow wyprodukuje zbior(vector)(tych samych) stanowisk
    vector<product>::iterator it;
    for(i=0, it=prod.begin(); it<prod.end(); i++, it++){
        if(prod[i].result()==true)
            howMany++;
    }
    return(howMany);
}

template<class A>
void factory::fillVector(vector<A> &item, int number){
    for(int i=0; i<number; i++){
        A temporary;
        item.push_back(temporary);
    }
}
