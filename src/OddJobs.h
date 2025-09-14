#ifndef RENTTRACKER_H
#define RENTTRACKER_H

struct RentTracker {
    int** expenses;      // 2D array [month][category]
    int numMonths;       // Number of months
    int numCategories;   // Number of expense categories
};

// Create and initialize tracker
RentTracker* createTracker(int months, int categories);

// Record an expense
void recordExpense(RentTracker* tracker, int month, int category, int amount);

// Get total for a month
int getMonthTotal(RentTracker* tracker, int month);

// Get total for a category
int getCategoryTotal(RentTracker* tracker, int category);

// Find month with highest expenses
int findWorstMonth(RentTracker* tracker);

// Calculate average monthly expense
int calculateAverage(RentTracker* tracker);

// Create deep copy
RentTracker* copyTracker(RentTracker* original);

// Clear a month's data
void clearMonth(RentTracker* tracker, int month);

// Print report
void printReport(RentTracker* tracker);

// Clean up memory
void destroyTracker(RentTracker* tracker);

#endif
