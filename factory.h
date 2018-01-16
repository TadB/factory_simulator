#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class product{
protected:
    // string name;
    vector<queue<int>> Q; //wektor kolejek typu int - w zaleznosci od produktu moze byc kilka elementow potrzebnych do zlozenia
public:

    int pushResult(); //przekazuje wyprodukowany produkt do magazynu, typu int w celu zliczania ilosci wyprodukowanych sztuk
    queue<int>* addQueue(); //zwraca wskaznik na nowo dodana kolejke (dla stanowiska z elementami)
};
class element{
protected:
    // string name;
    vector<product*>path; //wektor wskaznikow na produkty, ktore beda wytwarzane z tych elementow
public:
    void timeStep();//krok czasowy po ktorym wysylany jest przedmiot do nastepnego stanowiska
    void getDirection(); //decyduje gdzie przekazac nastepny element(do ktorego stanowiska) - decyduje dlugosc kolejki przy stanowisku
    void addSlotAdress(product*);//dodaje kolejny wskaznik do wektora path, dodaje ten ktory dostalo w argumencie

};
