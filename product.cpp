#include"factory.h"

int product::pushResult(){
return 1;
}

queue<int>* product::addQueue(){
    queue<int> temp;
    Q.push_back(temp);
    return (&Q.back()); //zwraca adres nowo dodanego elementu wektora
}
