#include "factory.h"

//konstruktory
factory::factory(){
    // cout<<"nie ma pustych fabryk!";
    // exit(0);
}

factory::factory(int tableNo, int tableTime, int lockerNo, int lockerTime,int legNo, int legTime,int desktopNo, int desktopTime, int doorNo, int doorTime, int casingNo, int casingTime):storehouseTable(0), storehouseLocker(0){
    if((tableNo==0) ||(lockerNo==0) ||(legNo==0) ||(desktopNo==0) ||(doorNo==0) ||(casingNo==0)){
        cout<<"fabryka jest niepelna nie mozna tak produkowac"<<endl;
        exit(0);
    }
//{{{ uzupelnianie listow zadana liczba stanowisk
    filllist(table, tableNo, "table", tableTime);
    filllist(locker, lockerNo, "locker", lockerTime);
    filllist(leg, legNo, legTime);
    filllist(desktop, desktopNo, desktopTime);
    filllist(door, doorNo, doorTime);
    filllist(casing, casingNo, casingTime);
    makeGraph(desktop, table);
    makeGraph(leg, table);
    makeGraph(door, locker);
    makeGraph(leg, locker);
    makeGraph(casing, locker);
//}}}
}

void factory::run(int counter){
    //{{{przekazujemy polprodukty do stacji montazowych
    //wystarczy sprawdzac tylko pierwszy element listy, reszta ma takie same czasy wykonania
    if((*desktop.begin()).isMade(counter))
        runElement(desktop);
    if((*door.begin()).isMade(counter))
        runElement(door);
    if((*leg.begin()).isMade(counter))
        runElement(leg);
    if((*casing.begin()).isMade(counter))
        runElement(casing);
    //}}}
    //{{{ powiekszamy magazyny
    int count=0;
    if((*table.begin()).isMade(counter)){
        count = runProduct(table);
        storehouseTable+=count;
    }
    if((*locker.begin()).isMade(counter)){
        count = runProduct(locker);
        storehouseLocker+=count;
    }
    //}}}
}

void factory::printRes(){
    printQ(table);
    printQ(locker);
    cout<<"stolow wyprodukowano: "<<storehouseTable<<endl;
    cout<<"szafek wyprodukowano: "<<storehouseLocker<<endl;
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
void factory::filllist(list<A> &item, int number, int timer){
    for(int i=0; i<number; i++){
        A temporary(timer);
        item.push_back(temporary);
    }
}
template<class A>
void factory::filllist(list<A> &item, int number, string text, int timer){
    for(int i=0; i<number; i++){
        A temporary(text, timer);
        item.push_back(temporary);
    }
}

// template<class A>
void factory::printQ(list<product> &item){
    list<product>::iterator it;
    int n=0;
    // string text=(*it).getName();
    cout<<(*item.begin()).getName()<<endl;
    for(n=0, it=item.begin(); it!=item.end(); n++, it++){
        cout<<"kolejki przy stanowisku nr: "<<n+1<<" -> ";
        (*it).countQ();
        cout<<endl;
    }
}
