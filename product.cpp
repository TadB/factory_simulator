#include"product.h"

// product::product(): Q() {}

bool product::result(){
    //sprawdzanie kazdej z kolejek, jesli kazda jest niepusta to mozna wykonac przedmioty
    // bool production=false;
    int i;
    vector<int>::iterator it;
    for(i=0, it=Q.begin(); it<Q.end(); i++, it++){
        if(Q.at(i)==0){
            // production=false;
            return(false);
        }
        // else
        //     production=true;
    }
    //jesli program tutaj dojdzie, to znaczy ze nie zworocil false, czyli nie wyszedl z funkcji wiec zworci true
    //nalezy jeszcze tylko zmniejszyc kolejki podzespolow, bo uzywamy ich do produkcji
    for(i=0, it=Q.begin(); it<Q.end(); i++, it++) (Q.at(i))--;

    return(true);
}

int* product::addQueue(){
    int temp=0;
    Q.push_back(temp);
    return (&Q.back()); //zwraca adres nowo dodanego elementu wektora
}
