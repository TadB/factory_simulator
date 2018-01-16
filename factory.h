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
public:
    factory();
    factory(int, int, int, int, int, int);

};

#endif
