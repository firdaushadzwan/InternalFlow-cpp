#include "InternalFlow.h"

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
