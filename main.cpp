#include<unistd.h>
#include"factory.h"

int main(){
    factory simulation(1,2,4,4,4,4);
    for(int i=0; i<124; i++){
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
