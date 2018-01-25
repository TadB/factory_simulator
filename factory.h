//to bedzie moja fabryka - czyli klasa graf, ktora bedzie zestawiac polaczenia pomiedzy stanowiskami
#ifndef FACTORY_H
#define FACTORY_H
#include"product.h"
#include"element.h"



class factory{
private:
    // wektory jako pudelka na stanowiska montujace i wytwarzajace poszczegolne przedmioty
    list<product> table;
    list<product> locker; //szafki xd

    list<element> leg;
    list<element> desktop;
    list<element> door;
    list<element> casing; //obudowa

    //magazyn wyprodukowanych elementow
    int storehouseTable, storehouseLocker;

    template<class A>
    void filllist(list<A>&, int, string, int);
    template<class A>
    void filllist(list<A>&, int, int);
    void runElement(list<element>&);
    int runProduct(list<product>&);
    void printQ(list<product>&);
public:
    factory();
    factory(int, int, int, int, int, int, int, int, int, int, int, int);

    void makeGraph(list<element>&, list<product>&);
    void run(int);
    void printRes();

};

#endif
