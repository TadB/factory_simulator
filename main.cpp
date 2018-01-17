#include<unistd.h>
#include"factory.h"

int main(){
    factory simulation(1,1,2,2,2,2);
    for(int i=0; i<4; i++){
        usleep(2000*1000);
        simulation.run();
    }
    simulation.printRes();
    return(0);
}
