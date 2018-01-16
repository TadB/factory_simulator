#ifndef ELEMENT_H
#define ELEMENT_H
#include"product.h"


class element{
protected:
    // string name;
    vector<queue<int>*>path; //wektor wskaznikow na produkty, ktore beda wytwarzane z tych elementow
public:
    //  void timeStep();//krok czasowy po ktorym wysylany jest przedmiot do nastepnego stanowiska
    queue<int>* getDirection(); //decyduje gdzie przekazac nastepny element(do ktorego stanowiska) - decyduje dlugosc kolejki przy stanowisku
    void addSlotAdress(queue<int>*);//dodaje kolejny wskaznik do wektora path, dodaje ten ktory dostalo w argumencie

};

#endif
