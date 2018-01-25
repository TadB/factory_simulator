#include"handler.h"
#include<unistd.h>
#include<fstream>


factory userIns(){
//{{{ stanowiska wytwarzajace polfabrykaty
    int leg, desktop, door, casing;
    int legTime, desktopTime, doorTime, casingTime;
    cout<<"podaj ilosc stanowisk wytwarzajacych: "<<endl;
    cout<<" nogi: ";
    cin>>leg;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>legTime;
    cout<<"blaty: ";
    cin>>desktop;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>desktopTime;
    cout<<"drzwiczki: ";
    cin>>door;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>doorTime;
    cout<<"obudowy: ";
    cin>>casing;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>casingTime;
//}}}
//{{{ stanowiska skladajace produkty
    int table, locker;
    int tableTime, lockerTime;
    cout<<"podaj ilosc stanowisk skaldajacych: "<<endl;
    cout<<" stoly: ";
    cin>>table;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>tableTime;
    cout<<"szafki: ";
    cin>>locker;
    cout<<"podaj czas wykonania jednej sztuki: ";
    cin>>lockerTime;
//}}}
    int timer=12;
    cout<<"wprowadz czas trwania symulacji(w sekundach): ";
    cin>>timer;
    cout<<endl;

    factory simulation(table, tableTime, locker, lockerTime, leg, legTime, desktop, desktopTime, door, doorTime, casing, casingTime);
    simulationRun(simulation, timer);
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
        cout<<"9 - ";
        cout<<"zakoncz program"<<endl;
        cout<<"wprowadz jedna z podanych opcji: ";
        cin>>c;
        clearScreen();
        switch(c){
            case '1':{
                factory simulation(1,1,1,1,2,1,4,1,2,1,4,1);
                simulationRun(simulation, 20);
                cout<<"wcisnij enter aby kontynuowac"<<endl;
                system("read");
            }
                break;
            case '2':{
                factory results;
                results = userIns();
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


void simulationRun(factory &sim, int timer){

    for(int i=0; i<timer; i++){
           usleep(100*1000);
           sim.run(i);
       }
    sim.printRes();

}


void clearScreen(){
    cout << string( 100, '\n' );
}
