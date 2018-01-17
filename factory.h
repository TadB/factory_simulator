//to bedzie moja fabryka - czyli klasa graf, ktora bedzie zestawiac polaczenia pomiedzy stanowiskami
#ifndef FACTORY_H
#define FACTORY_H
#include"product.h"
#include"element.h"



class factory{
private:
    // wektory jako pudelka na stanowiska montujace i wytwarzajace poszczegolne przedmioty
    vector<product> table;
    vector<product> locker; //szafki xd

    vector<element> leg;
    vector<element> desktop;
    vector<element> door;
    vector<element> casing; //obudowa

    //magazyn wyprodukowanych elementow
    int storehouseTable, storehouseLocker;

    template<class A>
    void fillVector(vector<A>&, int);
    void runElement(vector<element>&);
    int runProduct(vector<product>&);
public:
    factory();
    factory(int, int, int, int, int, int);

    void makeGraph(vector<element>&, vector<product>&);
    void run();
    void printRes();

};

#endif
