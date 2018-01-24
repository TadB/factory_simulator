#ifndef ELEMENT_H
#define ELEMENT_H
#include"product.h"


class element{
private:
    // string name;
    list<int*> path; //wektor wskaznikow na produkty, ktore beda wytwarzane z tych elementow
    int interval; //czas wykonywania danego podzespolu
public:
    element(int);
    //  void timeStep();//krok czasowy po ktorym wysylany jest przedmiot do nastepnego stanowiska
    int* getDirection(); //decyduje gdzie przekazac nastepny element(do ktorego stanowiska) - decyduje dlugosc kolejki przy stanowisku
    void addSlotAdress(int*);//dodaje kolejny wskaznik do wektora path, dodaje ten ktory dostalo w argumencie
    bool isMade(int);

};

#endif
