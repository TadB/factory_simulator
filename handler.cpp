#include"handler.h"
#include<unistd.h>
#include<fstream>

//reset buffer to default
void resetBuf(){
    std::string line;
    while(std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }
}

void userIns(){
//{{{ stanowiska wytwarzajace polfabrykaty
    int leg, desktop, door, casing;
    cout<<"podaj ilosc stanowisk wytwarzajacych: "<<endl;
    cout<<" nogi: ";
    cin>>leg;
    cout<<"\n blaty: ";
    cin>>desktop;
    cout<<"\n drzwiczki: ";
    cin>>door;
    cout<<"\n obudowy: ";
    cin>>casing;
//}}}
//{{{ stanowiska skladajace produkty
    int table, locker;
    cout<<"podaj ilosc stanowisk skaldajacych: "<<endl;
    cout<<" stoly: ";
    cin>>table;
    cout<<"\n szafki: ";
    cin>>locker;
//}}}
    factory simulation(table, locker, leg, desktop, door, casing);
}
void mainMenu(){
    char c, confirm;
    do{
        //refreshScreen
        cout<<"Symulator fabryki mebli: "<<endl;
        cout<<"MENU: \n";
        cout<<"1 - ";
        cout<<"uruchom symulacje z domyslnymi wartosciami"<<endl;
        cout<<"2 - ";
        cout<<"wczytaj wartosci z palca"<<endl;
        cout<<"3 - ";
        cout<<"zapisz do pliku"<<endl;
        cout<<"4 - ";
        cout<<"wyswietl wyniki na ekranie"<<endl;
        cout<<"5 - ";
        cout<<"wczytaj z pliku"<<endl;
        cout<<"9 - ";
        cout<<"zakoncz program"<<endl;
        cout<<"wprowadz jedna z podanych opcji: ";
        cin>>c;
        clearScreen();
        switch(c){
            case '1':{
                factory simulation(1,1,2,4,2,4);
                for(int i=0; i<12; i++){
                       usleep(100*1000);
                       simulation.run();
                   }
                simulation.printRes();
                cout<<"wcisnij enter aby kontynuowac"<<endl;
                system("read");
            }
                break;
            case '2':{
                userIns();
            }
                break;
            case '3':
                break;
            case '4':
                break;
            case '9':
                cout<<"czy napewno chcesz zakonczyc program? T/n: "; //tak jest domyslna opcja, wprowadzenie dowolnego znaku (oprocz 'n') spowoduje zakonczenie programu
                cin>>confirm;
                if(confirm=='n')
                    c='x';//zmienia c na dowolne inne, aby nie zakonczyc programu
                break;
            default:
                cout<<"nie rozpoznano komendy"<<endl;
                cout<<"wcisnij enter aby kontynuowac"<<endl;
                system("read");
                break;
        }
        clearScreen();
    }while(c!='9');
}

void simulationRun(){

    mainMenu();
//
    // factory simulation(1,1,2,4,2,4);
//     for(int i=0; i<12; i++){
//         usleep(100*1000);
//         simulation.run();
//     }
// simulation.printRes();
}


void clearScreen(){
    cout << string( 100, '\n' );
}