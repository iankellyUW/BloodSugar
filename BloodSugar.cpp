// IAN L KELLY
// COSC 2030
// PROJECT 1
// OCTOBER 20, 2018

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
using std::abs;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stod;

//declaring functions that will be used in the body of the program
void printGreeting();
void takeInput(LinkedList &data);
void entry(LinkedList &data, float entry);
void entry(LinkedList &data, string entry);
void printWeek();
void updateWeek(LinkedList list[], int size);

// Daily counters =====
int day = 0;
//=====================

// Weekly Counts ======
int week = 0;
float wksum = 0.0;
float wkmax = 0.0;
float wkmin = 0.0;
long wkcount = 0;
int wkMaxFloats = 0;
int highDelta = 0;
int largestDay = 0;
//=====================

// Body of the program
int main()
{
	// Create two arrays that store Linear Linked Lists (LLLists / Lists), one for each day of the week.
	LinkedList weekOne[7];
	LinkedList weekTwo[7];

	// Explain the program to the user
	printGreeting();

	// Start taking inputs from the user for the first week
	while (day < 7) {
		// Update the weekly summary of the first week every time data is entered
		updateWeek(weekOne, 7);
		// Take and handle input from the user until the user is done entering data
		takeInput(weekOne[day]);
	}

	// After the first week is over, we start on day 0 and week n + 1
	// Reset all values
	day = 0;
	week = 1;
	wksum = 0.0;
	wkmax = 0.0;
	wkmin = 0.0;
	wkcount = 0;
	wkMaxFloats = 0;
	highDelta = 0;
	largestDay = 0;

	// Start taking inputs from the user for the second week
	while (day < 7) {

		// Update the weekly summary of the second week every time data is entered
		updateWeek(weekTwo, 7);

		// Take and handle input from the user until the user is done entering data
		takeInput(weekTwo[day]);
	}

	//After the user is done entering data for both weeks, ouput a summary of both week's entries
	cout << "The two weeks are over, here is a summary: " << endl;

	// Update week one's summary
	updateWeek(weekOne, 7);
	// change the week to week one
	week = 0;
	// print current week's summary
	printWeek();

	// Update week two's summary
	updateWeek(weekTwo, 7);
	//change the week to week two
	week = 1;
	//print the current week's summary
	printWeek();

	//program is finished
	return 0;
}

// When the program starts, give the user instructions for operating the program.
void printGreeting() {
	cout << "This program stores the blood sugar level on a daily and weekly basis for two weeks." << endl;
	cout << "Enter 'D' or 'Day' to see a summary of the day so far." << endl;
	cout << "Enter 'W' or 'Week' to see a summary of the week so far." << endl;
	cout << "After you are done entering values, enter 'N' or 'Next' to go to the next day." << endl;
	cout << "It is Day 1, Week 1. A final summary will be printed after day 7, week 2." << endl;
}

// Handle any input given for the current day
void takeInput(LinkedList &data) {
	string b;
	float db;

	// Accept any of the user's input as a string
	cin >> b;

	// Attempt to convert any good data to a double and pass it through as an entry for the current day
	try
	{
		db = stof(b);
		entry(data, db);
	}
	// if this fails, catch the error and pass the string through as an entry for the current day
	catch (std::exception& e)
	{
		entry(data, b);
	}
}

// If the entry is passed through as a double, check that it is greater than 0, and add it to the List on the current day
void entry(LinkedList &list, float entry) {
	if (entry > 0) {
		list.insertAsLast(entry);
		// Let the user know if the data was good, and it was added
		cout << "Entry added." << endl;
	}
}

// If the entry failed to convert to a double, check for "N", "D", and "W"; handle appropriately
void entry(LinkedList &list, string entry) {
	// N changes the day to the next day
	if (entry.compare("N") == 0) {
		if (day < 7) {
			// Change the day to the next day
			day++;
			// If the day is less than day "7", let the user know the day
			if (day <= 6) {
				cout << "It is now day " << day + 1 << "." << endl;
			}
			// If the day is "8" (saturday of week 2), let the user know the day has changed
			else if (week < 1) {
				cout << "It is now day 1, week " << week + 2 << endl;
			}
			// The main body will know when/how to change weeks
		}
	}

	// Print a daily summary
	if (entry.compare("D") == 0) {
		// What day is it?
		cout << "==== Daily summary for day " << day + 1 << ", week " << week + 1 << " ======================================" << endl;

		// What is the sum of all the entries in the current day's list?
		cout << "Sum of all readings today: " << list.sum();
		// Is the sum too big? If it is, output a "corrected" value.
		if (list.getMaxFloats() > 0) {
			cout << " * " << list.getMaxFloats() << " * MAX_FLOAT(" << FLT_MAX << ")";
			/*
				3.402823466e+38 mg/dL
				If your blood sugar was this high, you would have about 330 times the mass of an O-Type Main-Sequence star kilograms of glucose in your blood.
			*/

		}
		cout << endl;
		// Get the max and minimum values in today's list.
		cout << "Maximum reading today: " << list.max() << endl;
		cout << "Minimum reading today: " << list.min() << endl;
		// Get a count of all the entries today as well.
		cout << "Total number of readings today: " << list.getCount() << endl;
		cout << "====================================================================" << endl << endl;
	}

	// Use a special function to print a weekly summary
	if (entry.compare("W") == 0) {
		printWeek();
	}
}

// Function for printing the weekly stats
void printWeek()
{
	// Every time the user presses enter, the weekly summary is updated so this function can print it

		//What week is it?
	cout << "==== Weekly summary for week " << week + 1 << " ======================================" << endl;
	cout << "Sum of all readings this week: " << wksum;
	// Check for overflown data, print in proper notation
	if (wkMaxFloats > 0) {
		cout << " * " << wkMaxFloats << " * MAX_FLOAT(" << FLT_MAX << ")";
	}
	cout << endl;
	cout << "Maximum reading this week: " << wkmax << endl;
	cout << "Minimum reading this week: " << wkmin << endl;
	cout << "Total number of readings this week: " << wkcount << endl;
	cout << "The day with the largest difference is day: " << largestDay + 1 << ", with a difference of " << highDelta << "." << endl;
	cout << "====================================================================" << endl << endl;
}

void updateWeek(LinkedList list[], int size) {
	// iterate through the list taking sums, total count, min, and max.
	// store variables for taking the delta
	long count(0);
	long overflown(0);
	int prev = 0;
	int prevDelta = 0;
	int currentDelta = 0;
	int highestDelta = 0;
	int highestDay = 0;
	float max(0.0), min(0.0), sum(0.0);

	// Iterate through every weekday
	for (int i = 0; i < size; i++) {

		// Find the delta. Day 1 should be the largest day at first.
		if (i == 0) {
			largestDay = i;
			prev = list[i].getCount();
		}
		// On day two, delta is the difference between days 1 and two. The previous delta and days are set now.
		// On day three, the previous delta is compared to the difference of days two and three, and the previous day is set.
		// Etc.
		else if (i <= day) {
			prevDelta = currentDelta;
			currentDelta = abs(list[i].getCount() - prev);
			if (currentDelta > highestDelta) {
				highestDelta = currentDelta;
				highestDay = i;
			}
			prev = list[i].getCount();
		}

		//Keep track of how many times the summation has gone over the maximum amount a float can hold
		overflown += list[i].getMaxFloats();
		count += list[i].getCount();
		// If the float gets maxed out in an addition, iterate the overflow and subtract the maximum float value
		if ((sum + list[i].sum()) == INFINITY) {
			// is the sum greater than what is being added? subtract max float from the sum
			if (sum > list[i].sum()) {
				float temp = 0;
				temp = sum - FLT_MAX;
				sum = 0;
				sum += temp + list[i].sum();
				overflown++;
			}
			// is what's being added greater than the sum? subtract max float from the addition
			else {
				sum += list[i].sum() - FLT_MAX;
				overflown++;
			}
		}
		// if all is good, just add the two.
		else {
		sum += list[i].sum();
		}
		//check the minimum values, compare, and change if needed
		if (!list[i].empty()) {
			if (min > list[i].min() || i == 0 || count == 1) {
				min = list[i].min();
			}
		}
		// check the max value, compare, and change if needed
		if (max < list[i].max()) {
			max = list[i].max();
		}
	}

	// set all the global values to the correct updated values
	highDelta = highestDelta;
	largestDay = highestDay;
	wkMaxFloats = overflown;
	wksum = sum;
	wkcount = count;
	wkmin = min;
	wkmax = max;
}