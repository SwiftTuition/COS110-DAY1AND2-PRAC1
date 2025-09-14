#include "../src/RentTracker.h"
#include <iostream>
#include <iomanip>
using namespace std;

int testsPassed = 0;
int totalTests = 0;
int functionalityScore = 0;

void test(bool condition, const char* testName, int points) {
    totalTests++;
    if (condition) {
        cout << "[PASS] " << testName << " (" << points << " points)" << endl;
        testsPassed++;
        functionalityScore += points;
    } else {
        cout << "[FAIL] " << testName << " (0/" << points << " points)" << endl;
    }
}

int main() {
    cout << "===========================================" << endl;
    cout << "     COS110 DAY 1&2 PRACTICAL GRADING     " << endl;
    cout << "===========================================" << endl << endl;
    
    cout << "Running Functionality Tests..." << endl;
    cout << "-------------------------------" << endl;
    
    // Test 1: Create tracker (10 points)
    RentTracker* tracker = createTracker(4, 3);
    test(tracker != NULL, "Create tracker", 5);
    test(tracker != NULL && tracker->numMonths == 4, "Correct months", 2);
    test(tracker != NULL && tracker->numCategories == 3, "Correct categories", 3);
    
    // Test 2: Initial values (10 points)
    bool allZero = true;
    if (tracker != NULL && tracker->expenses != NULL) {
        for(int i = 0; i < 4 && allZero; i++) {
            for(int j = 0; j < 3 && allZero; j++) {
                if(tracker->expenses[i][j] != 0) allZero = false;
            }
        }
    } else {
        allZero = false;
    }
    test(allZero, "All values initialized to 0", 10);
    
    // Test 3: Record expenses (10 points)
    if (tracker != NULL) {
        recordExpense(tracker, 0, 0, 100);
        recordExpense(tracker, 0, 1, 200);
        recordExpense(tracker, 1, 0, 150);
        test(tracker->expenses[0][0] == 100, "Record expense 1", 3);
        test(tracker->expenses[0][1] == 200, "Record expense 2", 3);
        test(tracker->expenses[1][0] == 150, "Record expense 3", 4);
    }
    
    // Test 4: Get month total (10 points)
    int monthTotal = getMonthTotal(tracker, 0);
    test(monthTotal == 300, "Get month total", 10);
    
    // Test 5: Get category total (10 points)
    int catTotal = getCategoryTotal(tracker, 0);
    test(catTotal == 250, "Get category total", 10);
    
    // Test 6: Find worst month (5 points)
    if (tracker != NULL) {
        recordExpense(tracker, 2, 2, 500);
    }
    int worst = findWorstMonth(tracker);
    test(worst == 2, "Find worst month", 5);
    
    // Test 7: Calculate average (5 points)
    int avg = calculateAverage(tracker);
    test(avg == 237, "Calculate average", 5);
    
    // Test 8: Copy tracker (15 points)
    RentTracker* copy = copyTracker(tracker);
    test(copy != NULL, "Copy created", 5);
    test(copy != NULL && copy != tracker, "Copy is different object", 5);
    if (copy != NULL && tracker != NULL) {
        test(copy->expenses[0][0] == 100, "Copy has correct values", 5);
    }
    
    // Test 9: Clear month (5 points)
    if (tracker != NULL) {
        clearMonth(tracker, 0);
        test(tracker->expenses[0][0] == 0, "Clear month works", 5);
    }
    
    // Test 10: Destroy doesn't crash (10 points)
    bool nocrash = true;
    destroyTracker(tracker);
    destroyTracker(copy);
    test(nocrash, "Destroy tracker works", 10);
    
    // CALCULATE FINAL SCORES
    cout << endl;
    cout << "===========================================" << endl;
    cout << "              FINAL SCORES                 " << endl;
    cout << "===========================================" << endl;
    
    int maxFunctionalityScore = 90;
    double funcPercentage = (functionalityScore * 60.0) / maxFunctionalityScore;
    
    cout << "Functionality Score: " << functionalityScore << "/" << maxFunctionalityScore 
         << " (" << fixed << setprecision(1) << funcPercentage << "/60%)" << endl;
    
    cout << "Memory Score: Run 'make memcheck' to check" << endl;
    cout << "             (Worth 40% of total grade)" << endl;
    
    cout << endl;
    cout << "===========================================" << endl;
    cout << "TOTAL GRADE SO FAR: " << funcPercentage << "/60%" << endl;
    cout << "===========================================" << endl;
    
    cout << endl;
    cout << "IMPORTANT: Run 'make memcheck' to test memory management!" << endl;
    cout << "Memory leaks will cost you 40% of your grade!" << endl;
    
    return 0;
}
