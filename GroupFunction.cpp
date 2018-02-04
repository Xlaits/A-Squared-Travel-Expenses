// Ran Xu 2/1/2018 C++ T/R
// Group Function Page 405 Number 20
// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
// (library)

void totalDays(int &Days);
void tripTimes(int &hourLeave, int &minLeave, int &hourBack, int &minBack);
void hotelCost(int Days, float &Covered, float &notCovered);
// (declaration)

int main() {

	int day, hour1, hour2, min1,min2;
	float free=0, pay=0;
	totalDays(day);
	tripTimes(hour1, min1, hour2, min2);
	hotelCost(day, free, pay);
	cout << "\n" << day << "\n" << hour1 << "\n" << hour2 << "\n" << min1 << "\n" << min2 << "\n" << free << "\n" << pay;
	cout << "\n\n";

	return 0;

}// (main)

/*
Made by: Ran Xu
This function use pass by reference to ask the user for the total number of days in the trip
*/

void totalDays(int &Days) {

	cout << "Enter the total number of days spent on the trip: ";
	cin >> Days;

	while ((Days <= 0) || (cin.fail())) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, negative number or non numeric value or 0 days\nEnter the total number of days spent on the trip: ";
		cin >> Days;

	}// (totalDays)(while)

}// (totalDays)

 /*
 Made by: Ran Xu
 This function use pass by reference to ask the user for the hour and minute for the first and last day of the trip
 with this combine with total number of days we can calculate how many breakfast, lunch, and dinner meals the user will have
 */

void tripTimes(int &hourLeave, int &minLeave, int &hourBack, int &minBack) {

	cout << "Enter the hour of departure on the first day of the trip in military time: ";
	cin >> hourLeave;

	while ((hourLeave > 24)||(hourLeave < 1) || (cin.fail())) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, hour should be between 1 to 24\nEnter the hour of departure on the first day of the trip in military time: ";
		cin >> hourLeave;

	}// (tripTimes)(while)

	cout << "Enter the minute of departure on the first day of the trip: ";
	cin >> minLeave;

	while ((minLeave > 59) || (minLeave < 0) || (cin.fail())) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, minute should be between 0 to 59\nEnter the minute of departure on the first day of the trip: ";
		cin >> minLeave;

	}// (tripTimes)(while)

	cout << "Departure time is " << hourLeave << ":" << minLeave << "\n";
	cout << "Enter the hour of arrival back home on the last day of the trip in military time: ";
	cin >> hourBack;

	while ((hourBack > 24) || (hourBack < 1) || (cin.fail())) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, hour should be between 1 to 24\nEnter the hour of arrival back home on the last day of the trip in military time: ";
		cin >> hourBack;

	}// (tripTimes)(while)

	cout << "Enter the minute of arrival back home on the last day of the trip: ";
	cin >> minBack;

	while ((minBack > 59) || (minBack < 0) || (cin.fail())) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, minute should be between 0 to 59\nEnter the minute of arrival back home on the last day of the trip: ";
		cin >> minBack;

	}// (tripTimes)(while)

	cout << "Return time is " << hourBack << ":" << minBack << "\n";

}// (tripTimes)

 /*
 Made by: Ran Xu
 This function use pass by reference and value to calculate the amount covered and amount pay for hotel expenses
 that will add onto the pre existing amount of covered and not covered fees
 */

void hotelCost(int Days, float &Covered, float &notCovered) {

	float Cost, Pay,Free;

	cout << "What is the total cost for hotel expenses?: $";
	cin >> Cost;
	Free = (Days - 1) * 90.0;
	Covered = Covered + Free;
	Pay = Cost - Free;
	notCovered = notCovered + Pay;
	cout << "Amount covered for hotel expenses: $" << fixed << setprecision(2) << Free << 
		"\nAmount not covered for hotel expenses: $" << Pay;

}// (hotelCost)