#include"product.h"

// product::product(): Q() {}

bool product::result(){
    //sprawdzanie kazdej z kolejek, jesli kazda jest niepusta to mozna wykonac przedmioty
    // int i;
    list<int>::iterator it;
    // list<int> *i;
    // i=it;
    for(it=Q.begin(); it!=Q.end(); it++){
        if(*(it)==0){
            // production=false;
            return(false);
        }
        // else
        //     production=true;
    }
    //jesli program tutaj dojdzie, to znaczy ze nie zworocil false, czyli nie wyszedl z funkcji wiec zworci true
    //nalezy jeszcze tylko zmniejszyc kolejki podzespolow, bo uzywamy ich do produkcji
    for(it=Q.begin(); it!=Q.end(); it++) (*it)--;

    return(true);
}

int* product::addQueue(){
    int temp=0;

    Q.push_back(temp);
    // Q[0]=0;
    // int* adress;
    // adress = &Q.back();
    return (&(Q.back())); //zwraca adres nowo dodanego elementu wektora
}
