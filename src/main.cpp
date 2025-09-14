
#include "RentTracker.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Gintoki's Rent Tracker Demo ===" << endl;
    
    // Create tracker for 3 months, 4 categories
    // Categories: 0=Rent, 1=Food, 2=Strawberry Milk, 3=Other
    RentTracker* tracker = createTracker(3, 4);
    
    // Record some expenses
    recordExpense(tracker, 0, 0, 1000);  // Month 0, Rent
    recordExpense(tracker, 0, 2, 500);   // Month 0, Strawberry Milk
    recordExpense(tracker, 1, 0, 1000);  // Month 1, Rent
    recordExpense(tracker, 1, 2, 750);   // Month 1, More milk...
    
    // Print report
    printReport(tracker);
    
    // Clean up
    destroyTracker(tracker);
    
    cout << "Demo complete!" << endl;
    return 0;
}
