// My Variable (Travel).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void travCost(float &air, float &milesPrice, float &parkingPrice, float &taxiPrice);

int main()
{
 
	float a, b, c, d;

	travCost(a, b, c, d);


	cout << "Your air miles are: " << fixed << setprecision(2) << a<<endl;
	cout << "Your rental miles are: "<< b<<endl;
	cout << "Your parking price is: " <<c<<endl;
	cout << "Your taxi cost is: "<< d<<endl;
	
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
