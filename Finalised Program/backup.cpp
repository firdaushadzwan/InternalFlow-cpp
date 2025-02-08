#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double g = 9.81;

class InternalFlow {
private:
    int numCases;
    int temperature[10];
    double diameter[10], length[10], avgVelocity[10], density[10], dynamicViscosity[10];
    double Re[10], f[10], epsilon[10], headLoss[10], pressureDrop[10], pumpingWork[10], volumeFlowRate[10], eD[10];

public:
    InternalFlow() {
    numCases = 0;
}
    void getInput() {
    cout << "*** Engineering Model: Internal Water Flow in Pipe Analysis ***" << endl;
    cout << "Enter the number of cases (up to 10): ";
    cin >> numCases;
    if (numCases > 10) numCases = 10;

    cout << "Enter the temperature (degree Celcius) for each case:" << endl;
    for (int i = 0; i < numCases; i++) {
        cout << "Case " << i + 1 << " Temperature: ";
        cin >> temperature[i];
    }

    cout << endl << "Select epsilon value for pipe material from the following options:" << endl;
    cout << left << setw(25) << "Materials" << setw(10) << "Epsilon (mm)" << endl;
    cout << left << setw(25) << "1) Glass, plastic" << setw(10) << "0" << endl;
    cout << left << setw(25) << "2) Concrete" << setw(10) << "0" << endl;
    cout << left << setw(25) << "3) Wood stave" << setw(10) << "0.5" << endl;
    cout << left << setw(25) << "4) Rubber, smoothed" << setw(10) << "0.01" << endl;
    cout << left << setw(25) << "5) Copper/ Brass tubing" << setw(10) << "0.0015" << endl;
    cout << left << setw(25) << "6) Cast iron" << setw(10) << "0.26" << endl;
    cout << left << setw(25) << "7) Galvanized iron" << setw(10) << "0.15" << endl;
    cout << left << setw(25) << "8) Wrought iron" << setw(10) << "0.046" << endl;
    cout << left << setw(25) << "9) Stainless steel" << setw(10) << "0.002" << endl;
    cout << left << setw(25) << "10) Commercial steel" << setw(10) << "0.045" << endl;

    for (int i = 0; i < numCases; i++) {
        int materialChoice;
        cout << "Case " << i + 1 << " Material (Enter 1-10): ";
        cin >> materialChoice;

        // Assign epsilon based on material choice
        switch (materialChoice) {
            case 1: epsilon[i] = 0; break;              // Glass, plastic
            case 2: epsilon[i] = 0; break;              // Concrete
            case 3: epsilon[i] = 0.5; break;            // Wood stave
            case 4: epsilon[i] = 0.01; break;           // Rubber, smoothed
            case 5: epsilon[i] = 0.0015; break;         // Copper/Brass tubing
            case 6: epsilon[i] = 0.26; break;           // Cast iron
            case 7: epsilon[i] = 0.15; break;           // Galvanized iron
            case 8: epsilon[i] = 0.046; break;          // Wrought iron
            case 9: epsilon[i] = 0.002; break;          // Stainless steel
            case 10: epsilon[i] = 0.045; break;         // Commercial steel
            default:
                cout << "Invalid choice! Defaulting to 0." << endl;
                epsilon[i] = 0;
        }
    }

    cout << endl << "Enter the pipe diameter (m) for each case:" << endl;
    for (int i = 0; i < numCases; i++) {
        cout << "Case " << i + 1 << " Diameter: ";
        cin >> diameter[i];
    }

    cout << endl << "Enter the pipe length (m) for each case:" << endl;
    for (int i = 0; i < numCases; i++) {
        cout << "Case " << i + 1 << " Length: ";
        cin >> length[i];
    }

    cout << endl << "Enter the average velocity (m/s) for each case:" << endl;
    for (int i = 0; i < numCases; i++) {
        cout << "Case " << i + 1 << " Velocity: ";
        cin >> avgVelocity[i];
    }
}
    void calculateDensity() {
    for (int i = 0; i < numCases; i++) {
        density[i] = (999.83952 + (16.945176 * temperature[i]) - 
                      (7.9870401e-3 * pow(temperature[i], 2.0)) - 
                      (46.170461e-6 * pow(temperature[i], 3.0)) + 
                      (105.56302e-9 * pow(temperature[i], 4.0)) - 
                      (280.54253e-12 * pow(temperature[i], 5.0))) / 
                     (1.0 + (16.897850e-3 * temperature[i]));
    }
}
    void dynamicViscositySelection() {
    for (int i = 0; i < 10; i++) {
        if (temperature[i] <= 0) {
            dynamicViscosity[i] = 0.001792;
        } else if (temperature[i] <= 5) {
            dynamicViscosity[i] = 0.001519;
        } else if (temperature[i] <= 10) {
            dynamicViscosity[i] = 0.001307;
        } else if (temperature[i] <= 15) {
            dynamicViscosity[i] = 0.001138;
        } else if (temperature[i] <= 20) {
            dynamicViscosity[i] = 0.001002;
        } else if (temperature[i] <= 25) {
            dynamicViscosity[i] = 0.000891;
        } else if (temperature[i] <= 30) {
            dynamicViscosity[i] = 0.000798;
        } else if (temperature[i] <= 35) {
            dynamicViscosity[i] = 0.000720;
        } else if (temperature[i] <= 40) {
            dynamicViscosity[i] = 0.000653;
        } else if (temperature[i] <= 45) {
            dynamicViscosity[i] = 0.000596;
        } else if (temperature[i] <= 50) {
            dynamicViscosity[i] = 0.000547;
        } else if (temperature[i] <= 55) {
            dynamicViscosity[i] = 0.000504;
        } else if (temperature[i] <= 60) {
            dynamicViscosity[i] = 0.000467;
        } else if (temperature[i] <= 65) {
            dynamicViscosity[i] = 0.000433;
        } else if (temperature[i] <= 70) {
            dynamicViscosity[i] = 0.000404;
        } else if (temperature[i] <= 75) {
            dynamicViscosity[i] = 0.000378;
        } else if (temperature[i] <= 80) {
            dynamicViscosity[i] = 0.000355;
        } else if (temperature[i] <= 85) {
            dynamicViscosity[i] = 0.000333;
        } else if (temperature[i] <= 90) {
            dynamicViscosity[i] = 0.000315;
        } else if (temperature[i] <= 95) {
            dynamicViscosity[i] = 0.000297;
        } else if (temperature[i] <= 100) {
            dynamicViscosity[i] = 0.000282;
        } else if (temperature[i] <= 110) {
            dynamicViscosity[i] = 0.000255;
        } else if (temperature[i] <= 120) {
            dynamicViscosity[i] = 0.000232;
        } else if (temperature[i] <= 130) {
            dynamicViscosity[i] = 0.000213;
        } else if (temperature[i] <= 140) {
            dynamicViscosity[i] = 0.000197;
        } else if (temperature[i] <= 150) {
            dynamicViscosity[i] = 0.000183;
        } else if (temperature[i] <= 160) {
            dynamicViscosity[i] = 0.000170;
        } else if (temperature[i] <= 170) {
            dynamicViscosity[i] = 0.000160;
        } else if (temperature[i] <= 180) {
            dynamicViscosity[i] = 0.000150;
        } else if (temperature[i] <= 190) {
            dynamicViscosity[i] = 0.000142;
        } else if (temperature[i] <= 200) {
            dynamicViscosity[i] = 0.000134;
        } else if (temperature[i] <= 220) {
            dynamicViscosity[i] = 0.000122;
        } else if (temperature[i] <= 240) {
            dynamicViscosity[i] = 0.000111;
        } else if (temperature[i] <= 260) {
            dynamicViscosity[i] = 0.000102;
        } else if (temperature[i] <= 280) {
            dynamicViscosity[i] = 0.000094;
        } else if (temperature[i] <= 300) {
            dynamicViscosity[i] = 0.000086;
        } else if (temperature[i] <=320) {
            dynamicViscosity[i] = 0.000078;
        } else if (temperature[i] <= 340) {
            dynamicViscosity[i] = 0.000070;
        } else {
            dynamicViscosity[i] = 0.000060; // For temperature[i] >= 360
        }
    }
}
    void ReynoldNumber() {
    for (int i = 0; i < numCases; i++) {
        Re[i] = (density[i] * avgVelocity[i] * diameter[i]) / dynamicViscosity[i];
    }
}
    void frictionFactor() {
    for (int i = 0; i < numCases; i++) {
        eD[i] = epsilon[i] / (1000 * diameter[i]);
        if (Re[i] < 2300) {
            f[i] = 64 / Re[i];
        } else {
            f[i] = pow(-1.8 * log10((6.9 / Re[i]) + pow((eD[i] / 3.7), 1.11)), -2);
        }
    }
}

    void mainCalculation() {
    for (int i = 0; i < numCases; i++) {
        volumeFlowRate[i] = avgVelocity[i] * M_PI * pow(diameter[i], 2) / 4;
        headLoss[i] = (f[i] * length[i] * pow(avgVelocity[i], 2)) / (2 * diameter[i] * g);
        pressureDrop[i] = f[i] * length[i] * density[i] * pow(avgVelocity[i], 2) / (2 * diameter[i]);
        pumpingWork[i] = volumeFlowRate[i] * pressureDrop[i];
    }
}
    void displayOutput(int caseIndex) {
    if (caseIndex < 0 || caseIndex >= numCases) {
        cout << "Invalid case index!" << endl;
        return;
    }
    cout << endl;
    cout << "Case " << caseIndex + 1 << " Results:" << endl;
    cout << fixed << setprecision(4);
    cout << "Reynold number: " << Re[caseIndex] << endl;
    cout << "Head Loss: " << headLoss[caseIndex] << " m" << endl;
    cout << "Pressure Drop: " << pressureDrop[caseIndex] << " Pa" << endl;
    cout << "Pumping Power: " << pumpingWork[caseIndex] << " W" << endl;
}
    int getNumCases() {
    return numCases;
}

};

int main() {
    InternalFlow flow;
    flow.getInput();
    flow.calculateDensity();
    flow.dynamicViscositySelection();
    flow.ReynoldNumber();
    flow.frictionFactor();
    flow.mainCalculation();

    while (true) {
        int caseIndex;
        cout << endl << "Enter the case number to view (1 to " << flow.getNumCases() << ", or 0 to exit): ";
        cin >> caseIndex;

        if (caseIndex == 0) break;
        flow.displayOutput(caseIndex - 1);
    }

    return 0;
}
