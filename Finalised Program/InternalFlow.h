#ifndef INTERNALFLOW_H
#define INTERNALFLOW_H

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double g = 9.81;

class InternalFlow {
private:
    int numCases;
    int temperature[10];
    double diameter[10], length[10], avgVelocity[10], 
        density[10], dynamicViscosity[10];
    double Re[10], f[10], epsilon[10], headLoss[10], 
        pressureDrop[10], pumpingWork[10], volumeFlowRate[10], eD[10];

public:
    InternalFlow();
    void getInput();
    void calculateDensity();
    void dynamicViscositySelection();
    void ReynoldNumber();
    void frictionFactor();
    void mainCalculation();
    void displayOutput(int caseIndex);
    int getNumCases();
};

#endif
