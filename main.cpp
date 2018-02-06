#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* *******************************************************************************************************
 * This is the main file that will bring all the functions together into a coherent, working program.    *
 * It will contain all the variables needed to hold the values for the other functions, as well as       *
 * any other things required for the program's requirements.                                             *
 *                                                                                                       *
 * This file will be edited and maintained solely by Andrew Roderigues. Any other edits will be          *
 * removed.                                                                                              *
 *********************************************************************************************************/

//Define Function Prototypes
float totalCost(float &airfare, float &meals, float &parking, float &hotel, float &vehicle);
double mealCost(int hourLeave, int minLeave, int hourBack, int minBack, int Days);
void travCost(float &air, float &milesPrice, float &parkingPrice, float &taxiPrice);
void totalDays(int &Days);
void tripTimes(int &hourLeave, int &minLeave, int &hourBack, int &minBack);
void hotelCost(int Days, float &Covered, float &notCovered);

int main()
{
		// Define Local Constants

		// Define Local Variables
        int Days, hourLeave, minBack, minLeave, hourBack;
        float airfare, meals, parking, hotel, vehicle, Covered, notCovered;

		// Begin Code
		totalDays(Days);
		tripTimes(hourLeave, minLeave, hourBack, minBack);
		hotelCost(Days, Covered, notCovered);
		totalCost(airfare, meals, parking, hotel, vehicle);
		mealCost(hourLeave, minLeave, hourBack, minBack, Days);
		travCost(airfare, meals, parking, vehicle);
		return 0;

}

//Robinson Meckes this function determines the round-trip airfair, Rental Car miles price, Parking price, and taxi price.
void travCost(float &air, float &milesPrice, float &parkingPrice, float &taxiPrice) {

	string vehicle;
	float miles = 0;
	float taxi = 0;
	float parking = 0;
	//determines the Air-Fair

	cout << "How much is your round-trip airfare.\n";
	cin >> air;
	while (air < 0) {
		cout << "Your round trip air-fair must be a must be positive.\n";
		cout << "How much was your air-fair?\n";
		cin >> air;
	}

	//Deterermines whether the person uses a rented car or taxi as transportation

	cout << "Did you rent a car or did you choose taxi as your form of transportation?\n";
	cout << "Enter either car or taxi.\n";
	cin >> vehicle;
	//cout << "Your input is: " << vehicle << endl;
	while (vehicle != "car" && vehicle != "Car" && vehicle != "taxi" && vehicle != "Taxi") {
		cout << "You can only enter either car or taxi.\n";
		cout << "Did you rent a car or did you choose taxi as your form of transportation?\n";
		cin >> vehicle;
	}


	//If "Car" is choosen

	if (vehicle == "car" || vehicle == "Car") {

		taxiPrice = 0;
		cout << "How many miles did you drive?\n";
		cin >> miles;

		while (miles < 0) {
			cout << "The amount of miles you have drivin must be positive.\n";
			cout << "How many miles did you drive?\n";
			cin >> miles;
		}

		milesPrice = miles * .58;
		cout << "How much was your fee for parking?\n";
		cin >> parking;

		while (parking < 0) {
			cout << "Your parking fee must be a must be positive.\n";
			cout << "How much was your parking fee?\n";
			cin >> parking;
		}

		parkingPrice = parking - 12;
		if (parkingPrice < 0) {
			parkingPrice = 0;
		}

	}

	//If "TAxi" is choosen

	if (vehicle == "taxi" || vehicle == "Taxi") {
		milesPrice = 0;
		parkingPrice = 0;
		cout << "How much was your taxi fee?\n";
		cin >> taxi;
		while (taxi < 0) {
			cout << "The price that you have spent on your taxi must be positive.\n";
			cout << "How much was your taxi fee?\n";
			cin >> taxi;
		}
		taxiPrice = taxi - 40;

		if (taxiPrice < 0) {
			taxiPrice = 0;
		}
	}

}

/*
Made by: Ran Xu
This function use pass by reference to ask the user for the total number of days in the trip
*/

void totalDays(int &Days) {

	cout << "Enter the total number of days spent on the trip: ";
	cin >> Days;

	while ((Days <= 0) || (cin.fail())) {

		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, negative number or non numeric value or 0 days\nEnter the total number of days spent on the trip: ";
		cin >> Days;

	}// (totalDays)(while)

}// (totalDays)
#include <string>
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
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, hour should be between 1 to 24\nEnter the hour of departure on the first day of the trip in military time: ";
		cin >> hourLeave;

	}// (tripTimes)(while)

	cout << "Enter the minute of departure on the first day of the trip: ";
	cin >> minLeave;

	while ((minLeave > 59) || (minLeave < 0) || (cin.fail())) {

		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, minute should be between 0 to 59\nEnter the minute of departure on the first day of the trip: ";
		cin >> minLeave;

	}// (tripTimes)(while)

	cout << "Departure time is " << hourLeave << ":" << minLeave << "\n";
	cout << "Enter the hour of arrival back home on the last day of the trip in military time: ";
	cin >> hourBack;

	while ((hourBack > 24) || (hourBack < 1) || (cin.fail())) {

		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, hour should be between 1 to 24\nEnter the hour of arrival back home on the last day of the trip in military time: ";
		cin >> hourBack;

	}// (tripTimes)(while)

	cout << "Enter the minute of arrival back home on the last day of the trip: ";
	cin >> minBack;

	while ((minBack > 59) || (minBack < 0) || (cin.fail())) {

		cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

//mealCost function written by Andrew Hoyt

double mealCost(int hourLeave, int minLeave, int hourBack, int minBack, int Days)
{
	double userTally;
	double userTotal = 0;
	double outOfPocket = 0;
	int count = 0;

	// loop to collect all breakfast meal costs

	while (count < Days) {
		count = count + 1;
		cout << "What was the cost of breakfast on day " << count << "?" << endl;
		cin >> userTally;
		// input validation loop
		while (userTally < 0) {
			cout << "Please enter a non-negative value for the cost of this meal.";
			cin >> userTally;
		}

		if (userTally < 18.00) {
			cout << "The cost for this meal will be covered." << endl;
			userTotal = userTotal + userTally;
		}

		if (userTally > 18.00) {
			cout << "Only $18.00 of this meal will be covered, the user will pay the difference." << endl;
			outOfPocket = outOfPocket + (userTally - 18.00);
			userTotal = userTotal + 18.00;
		}


	}

	count = 0;
	// loop to collect all lunch meal costs

	while (count < Days) {
		count = count + 1;
		cout << "What was the cost of lunch on day " << count << "?" << endl;
		cin >> userTally;
		// input validation loop
		while (userTally < 0) {
			cout << "Please enter a non-negative value for the cost of this meal.";
			cin >> userTally;
		}

		if (userTally < 12.00) {
			cout << "The cost for this meal will be covered." << endl;
			userTotal = userTotal + userTally;
		}

		if (userTally > 12.00) {
			cout << "Only $18.00 of this meal will be covered, the user will pay the difference." << endl;
			outOfPocket = outOfPocket + (userTally - 12.00);
			userTotal = userTotal + 12.00;
		}


	}

	count = 0;

	// loop to collect all dinner meal costs


	while (count < Days) {
		count = count + 1;
		cout << "What was the cost of dinner on day " << count << "?" << endl;
		cin >> userTally;
		// input validation loop
		while (userTally < 0) {
			cout << "Please enter a non-negative value for the cost of this meal.";
			cin >> userTally;
		}

		if (userTally < 20.00) {
			cout << "The cost for this meal will be covered." << endl;
			userTotal = userTotal + userTally;
		}

		if (userTally > 12.00) {
			cout << "Only $18.00 of this meal will be covered, the user will pay the difference." << endl;
			outOfPocket = outOfPocket + (userTally - 20.00);
			userTotal = userTotal + 20.00;
		}


	}

	// accounting for time user left, probably will need revision, i don't think this is right
	if (hourLeave < 0700) {
		userTotal = userTotal - 18.00;
	}
	if (hourLeave < 1200) {
		userTotal = userTotal - 12.00;
	}
	if (hourLeave < 1800) {
		userTotal = userTotal - 20.00;
	}

	return 0;
}


// Functions - Travel Expenses.cpp : Defines the entry point for the console application.
//

float totalCost(float &airfare, float &hotel, float &vehicle, float &meals, float &parking)
{
	float total;

	total= airfare+hotel+vehicle+meals+parking;

	cout << "The total cost of your trip was: " << endl;
	cout << "\t-------------------------";
	cout << "\t\t\t Airfare: $"<< airfare;
	cout << "\t\t\t   Hotel: $"<< hotel;
	cout << "\t\t\t vehicle: $" << vehicle;
	cout << "\t\t\t   Meals: $" << meals;
	cout << "\t\t\t Parking: $" << parking;
	cout << "\t-------------------------";
	cout << "The cost of your trip was: $" << total << endl;




}
