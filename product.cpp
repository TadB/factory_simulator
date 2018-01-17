#include"product.h"

product::product(){}

bool product::result(){
    //sprawdzanie kazdej z kolejek, jesli kazda jest niepusta to mozna wykonac przedmioty
    bool production=false;
    vector<queue<int>>::iterator it;
    for(it=Q.begin(); it<Q.end(); it++){
        if((*it).empty()==true)
            production=true;
        else
            production=false;
    }
    return(production);
}

queue<int>* product::addQueue(){
    queue<int> temp;
    Q.push_back(temp);
    return (&Q.back()); //zwraca adres nowo dodanego elementu wektora
}
