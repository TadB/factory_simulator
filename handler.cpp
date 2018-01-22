#include"handler.h"
#include<unistd.h>
#include<fstream>


factory userIns(){
//{{{ stanowiska wytwarzajace polfabrykaty
    int leg, desktop, door, casing;
    cout<<"podaj ilosc stanowisk wytwarzajacych: "<<endl;
    cout<<" nogi: ";
    cin>>leg;
    cout<<"blaty: ";
    cin>>desktop;
    cout<<"drzwiczki: ";
    cin>>door;
    cout<<"obudowy: ";
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
    int timer=12, timeStep=100;
    cout<<"wprowadz czas trwania symulacji(w sekundach): ";
    cin>>timer;
    cout<<"\npodaj czas wykonania jednej sztuki(w ms): ";
    cin>>timeStep;
    timer=timer*(int)(1000/timeStep);
    cout<<endl;

    factory simulation(table, locker, leg, desktop, door, casing);
    simulationRun(simulation, timer, timeStep);
    // simulation.printRes();
    return(simulation);
}
void start(){
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
        cout<<"wczytaj dane z pliku"<<endl;
        // cout<<"4 - ";
        // cout<<"wyswietl wyniki na ekranie"<<endl;
        // cout<<"5 - ";
        // cout<<"zapisz do pliku"<<endl;
        cout<<"9 - ";
        cout<<"zakoncz program"<<endl;
        cout<<"wprowadz jedna z podanych opcji: ";
        cin>>c;
        clearScreen();
        switch(c){
            case '1':{
                factory simulation(1,1,2,4,2,4);
                simulationRun(simulation, 20, 100);
                cout<<"wcisnij enter aby kontynuowac"<<endl;
                system("read");
            }
                break;
            case '2':{
                factory results;
                results = userIns();
                // getchar();
                cout<<"zapisac wyniki symulacji? t/N: ";
                cin>>confirm;
                if(confirm=='t'){
                    //zapisz do pliku - przekierowac wyjscie otowrzyc plik lub spytac o nazwe
                    string fileName;
                    cout<<"wprowadz nazwe pliku: ";
                    cin>>fileName;
                    fileName= fileName+".txt";
                    ofstream dataFile;
                    dataFile.open(fileName);
                    auto coutbuf=cout.rdbuf(dataFile.rdbuf()); //przekierowanie bufora na zapis do pliku dataFile
                    results.printRes();
                    cout.rdbuf(coutbuf); //reset do standardowego wyjscia 
                    cout<<"wcisnij enter aby kontynuowac"<<endl;
                    system("read");
                }
                else
                    clearScreen();
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


void simulationRun(factory &sim, int timer, int timeStep){

    for(int i=0; i<timer; i++){
           usleep(timeStep*1000);
           sim.run();
       }
    sim.printRes();
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
