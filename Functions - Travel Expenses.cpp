// Functions - Travel Expenses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

float totalCost(float &airfare, float &meals, float &parking, float &hotel, float &vehicle);



int main()
{


    return 0;
}

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