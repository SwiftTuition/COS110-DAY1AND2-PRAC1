#include "OddJobs.h"
#include <iostream>
using namespace std;

// Function 1: Initialize the job tracking system
// Creates a new JobTracker with specified weeks and days
// All earnings start at 0
JobTracker* createJobTracker(int weeks, int days) {
    // TODO: Complete this function
    
    return NULL;
}

// Function 2: Record a job's earnings
// Sets the earnings for jobs[week][day] to the specified amount
void recordJob(JobTracker* tracker, int week, int day, int earnings) {
    // TODO: Complete this function
    
}

// Function 3: Calculate total earnings for a specific week
// Returns sum of all earnings in the specified week
int getWeeklyTotal(JobTracker* tracker, int week) {
    // TODO: Complete this function
    
    return 0;
}

// Function 4: Calculate total earnings for the entire month
// Returns sum of all earnings across all weeks
int getMonthlyTotal(JobTracker* tracker) {
    // TODO: Complete this function
    
    return 0;
}

// Function 5: Find the most productive day
// Returns which day of week (0-6) had highest total earnings
int findBestDay(JobTracker* tracker) {
    // TODO: Complete this function
    
    return 0;
}

// Function 6: Count lazy days
// Returns number of days with 0 earnings
int countLazyDays(JobTracker* tracker) {
    // TODO: Complete this function
    
    return 0;
}

// Function 7: Apply rent deduction
// Reduces all non-zero earnings by given percentage
void applyRentDeduction(JobTracker* tracker, int percentage) {
    // TODO: Complete this function
    
}

// Function 8: Create a copy of the tracker
// Makes a complete deep copy with new memory allocation
JobTracker* copyTracker(JobTracker* original) {
    // TODO: Complete this function
    
    return NULL;
}

// Function 9: Print monthly report
void printReport(JobTracker* tracker) {
    // TODO: Complete this function
    // Format should be:
    // === Odd Jobs Report ===
    // Week 0: [day values] | Total: XXX
    // Week 1: [day values] | Total: XXX
    // etc...
    // Monthly Total: XXXX
    
}

// Function 10: Clean up all dynamic memory
// Must free ALL allocated memory properly
void destroyTracker(JobTracker* tracker) {
    // TODO: Complete this function
    // CRITICAL: Prevent memory leaks!
    
}
