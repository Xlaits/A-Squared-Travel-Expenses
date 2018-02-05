// My Variable (Travel).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void travCost(float &air, float &milesPrice, float &parkingPrice, float &taxiPrice);

int main()
{
 
	float a, b, c, d;

	travCost(a, b, c, d);



	
}

void travCost(float &air, float &milesPrice, float &parkingPrice, float &taxiPrice) {

	string vehicle;
	float miles = 0;
	
	//determines the Air-Fair
	
	cout << "How much is your round-trip airfare.\n";
	cin >> air;


	//Deterermines whether the person uses a rented car or taxi as transportation

	cout << "Did you rent a car or did you choose taxi as your form of transportation?\n";
	cout << "Enter either car or taxi.\n";
	cin >> vehicle;
	
	while (vehicle != "car" || "Car" || "taxi" || "Taxi") {
		cout << "You can only enter either car or taxi.\n";
		cout << "Did you rent a car or did you choose taxi as your form of transportation?\n";
		cin >> vehicle;
	}

	
	//If "Car" is choosen
	
	if (vehicle == "car" || "Car") {
		taxiPrice = 0;
		cout << "How many miles did you drive?\n";
		cin >> miles;
		while (miles < 0) {
			cout << "The amount of miles you have drivin must be positive.\n";
			cout << "How many miles did you drive?\n";
			cin >> miles;
		}
		milesPrice = miles * .58;
	}

	//If "TAxi" is choosen

	if (vehicle == "taxi" || "Taxi") {
		milesPrice = 0;
		parkingPrice = 0;
		cout << "How many miles did you drive in the taxi?\n";
		cin >> miles;
		while (miles < 0) {
			cout << "The amount of miles you have drivin must be positive.\n";
			cout << "How many miles did you drive in the taxi?\n";
			cin >> miles;
		}
		taxiPrice = (miles * .58)-40;

		if (taxiPrice < 0) {
			taxiPrice == 0;
		}
	}


}
