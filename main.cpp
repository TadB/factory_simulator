#include<unistd.h>
#include"factory.h"

int main(){
    factory simulation(1,1,2,4,2,4);
    for(int i=0; i<12; i++){
        usleep(100*1000);
        simulation.run();
    }
    // simulation.run();
    simulation.printRes();
    // simulation.run();
    // simulation.printRes();
    // simulation.run();
    // simulation.printRes();

    return(0);
}
