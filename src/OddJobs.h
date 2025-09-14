#ifndef ODDJOBS_H
#define ODDJOBS_H

/*
 * The Odd Jobs Management System
 * Track Gintoki's "work" to show his landlady he's trying to pay rent
 * 
 * Context: Gintoki Sakata runs "Odd Jobs Gin" - a business that will do 
 * any odd job for money. Problem is, he spends all earnings on strawberry
 * milk and parfaits, never paying rent to his landlady Otose.
 */

struct JobTracker {
    int** jobs;        // 2D array: [week][day] containing job earnings
    int numWeeks;      // Number of weeks in the month (typically 4)
    int daysPerWeek;   // Days per week (always 7)
};

// Function 1: Initialize the job tracking system
JobTracker* createJobTracker(int weeks, int days);

// Function 2: Record a job's earnings
void recordJob(JobTracker* tracker, int week, int day, int earnings);

// Function 3: Calculate total earnings for a specific week
int getWeeklyTotal(JobTracker* tracker, int week);

// Function 4: Calculate total earnings for the entire month
int getMonthlyTotal(JobTracker* tracker);

// Function 5: Find the most productive day
int findBestDay(JobTracker* tracker);

// Function 6: Count lazy days
int countLazyDays(JobTracker* tracker);

// Function 7: Apply rent deduction
void applyRentDeduction(JobTracker* tracker, int percentage);

// Function 8: Create a copy of the tracker
JobTracker* copyTracker(JobTracker* original);

// Function 9: Print monthly report
void printReport(JobTracker* tracker);

// Function 10: Clean up all dynamic memory
void destroyTracker(JobTracker* tracker);

#endif
