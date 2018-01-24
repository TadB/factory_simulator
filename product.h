#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<list>
#include<string>
// #include<queue>

using namespace std;

class product{
private:
    list<int> Q; //lista kolejek typu int - w zaleznosci od produktu moze byc kilka elementow potrzebnych do zlozenia
    // list<int> stopper; // zbiera informacje gdzie tworza sie najwieksze kolejki
    string name;
    int interval; //czas wykonywania danego podzespolu

public:
    product(string, int);
    bool result(); //przekazuje wyprodukowany produkt do magazynu, typu int w celu zliczania ilosci wyprodukowanych sztuk
    int* addQueue(); //zwraca wskaznik na nowo dodana kolejke (dla stanowiska z elementami)
    void countQ(); //funcja zliczajaca wielkosc kolejek przy stanowisku
    string getName(); //wypisuje nazwe stanowiska
    bool isMade(int);
};


#endif
