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
//{{{ uzupelnianie listow zadana liczba stanowisk
    filllist(table, tableNo);
    filllist(locker, lockerNo);
    filllist(leg, legNo);
    filllist(desktop, desktopNo);
    filllist(door, doorNo);
    filllist(casing, casingNo);
    makeGraph(desktop, table);
    makeGraph(leg, table);
    makeGraph(door, locker);
    makeGraph(leg, locker);
    makeGraph(casing, locker);


//}}}
}
void factory::makeGraph(list<element> &source, list<product> &dest){
    list<element>::iterator it;
    list<product>::iterator m;

    // int i=0 ,j=0;
    for(m=dest.begin(); m!=dest.end(); m++){
        int *temp;
        temp=(*m).addQueue();

        for( it=source.begin(); it!=source.end(); it++){
            (*it).addSlotAdress(temp);
            // int sprawdz = *(source[i].path[0]);
        } //w tej petli lacze stanowiska robiace podprodukty z adresami stanowiski skladajacych meble
    }
}
void factory::run(){
//{{{przekazujemy polprodukty do stacji montazowych
    runElement(desktop);
    runElement(door);
    runElement(leg);
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
void factory::runElement(list<element> &elem){
    list<element>::iterator it;
    // int i;
    int *index; //wskaznik na kolejke ktora jest najkrotsza - do niej wysylamy podzespol
    for(it=elem.begin(); it!=elem.end(); it++){
        if((*it).getDirection()!=NULL){
            index=(*it).getDirection();
            (*index)++;
        }//jesli getDirection() zwroci NULL to znaczy ze kolejka jest przepelniona i stanowisko musi poczekac
    }
}

int factory::runProduct(list<product> &prod){
    int howMany=0; //jak wiele produktow wyprodukuje zbior(list)(tych samych) stanowisk
    list<product>::iterator it;
    for(it=prod.begin(); it!=prod.end(); it++){
        if((*it).result()==true)
            howMany++;
    }
    return(howMany);
}

template<class A>
void factory::filllist(list<A> &item, int number){
    for(int i=0; i<number; i++){
        A temporary;
        item.push_back(temporary);
    }
}
