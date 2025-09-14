#include "../src/RentTracker.h"
#include <iostream>
using namespace std;

int testsPassed = 0;
int totalTests = 0;

void test(bool condition, const char* testName) {
    totalTests++;
    if (condition) {
        cout << "[PASS] " << testName << endl;
        testsPassed++;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    cout << "=== COS110 DAY 1&2 PRACTICAL TEST SUITE ===" << endl << endl;
    
    // Test 1-3: Basic Creation
    cout << "-- Basic Tests --" << endl;
    RentTracker* tracker = createTracker(4, 3);
    test(tracker != NULL, "Create tracker");
    test(tracker->numMonths == 4, "Correct months");
    test(tracker->numCategories == 3, "Correct categories");
    
    // Test 4-5: Initial values
    bool allZero = true;
    for(int i = 0; i < 4 && allZero; i++) {
        for(int j = 0; j < 3 && allZero; j++) {
            if(tracker->expenses[i][j] != 0) allZero = false;
        }
    }
    test(allZero, "All initialized to 0");
    
    // Test 6-8: Recording expenses
    cout << "\n-- Recording Tests --" << endl;
    recordExpense(tracker, 0, 0, 100);
    recordExpense(tracker, 0, 1, 200);
    recordExpense(tracker, 1, 0, 150);
    test(tracker->expenses[0][0] == 100, "Record expense 1");
    test(tracker->expenses[0][1] == 200, "Record expense 2");
    test(tracker->expenses[1][0] == 150, "Record expense 3");
    
    // Test 9-10: Calculations
    cout << "\n-- Calculation Tests --" << endl;
    test(getMonthTotal(tracker, 0) == 300, "Month 0 total");
    test(getCategoryTotal(tracker, 0) == 250, "Category 0 total");
    
    // Test 11: Find worst month
    recordExpense(tracker, 2, 2, 500);
    test(findWorstMonth(tracker) == 2, "Find worst month");
    
    // Test 12: Average
    int avg = calculateAverage(tracker);
    test(avg == 237, "Calculate average"); // (300+150+500+0)/4 = 237
    
    // Test 13-14: Copy tracker
    cout << "\n-- Deep Copy Tests --" << endl;
    RentTracker* copy = copyTracker(tracker);
    test(copy != NULL, "Copy created");
    test(copy->expenses != tracker->expenses, "Deep copy (different arrays)");
    test(copy->expenses[0][0] == 100, "Copy has correct values");
    
    // Modify copy and check independence
    recordExpense(copy, 0, 0, 999);
    test(tracker->expenses[0][0] == 100, "Original unchanged after copy modified");
    
    // Test 15: Clear month
    cout << "\n-- Clear Month Test --" << endl;
    clearMonth(tracker, 0);
    test(tracker->expenses[0][0] == 0, "Month cleared");
    
    // Clean up
    destroyTracker(tracker);
    destroyTracker(copy);
    
    // Results
    cout << "\n=== RESULTS ===" << endl;
    cout << "Tests passed: " << testsPassed << "/" << totalTests << endl;
    double percentage = (testsPassed * 100.0) / totalTests;
    cout << "Score: " << percentage << "%" << endl;
    
    if(percentage >= 90) {
        cout << "\nExcellent! Gintoki can afford strawberry milk!" << endl;
    } else if(percentage >= 70) {
        cout << "\nGood work! Otose is somewhat satisfied." << endl;
    } else if(percentage >= 50) {
        cout << "\nShinpachi says: 'At least you tried, Gin-san...'" << endl;
    } else {
        cout << "\nKagura says: 'You're hopeless, Gin-chan!'" << endl;
    }
    
    return 0;
}
