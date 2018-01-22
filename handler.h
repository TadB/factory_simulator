#ifndef HANDLER_H
#define HANDLER_H

#include<iostream>
#include"factory.h"

using namespace std;

void simulationRun(factory &, int, int);
void start();
// void resetBuf();
factory userIns();

void clearScreen();
#endif
