//mealCost function written by Andrew Hoyt
void mealCost(int hourLeave, int minLeave, int hourBack, int minBack);

double mealCost(int hourLeave, int minLeave, int hourBack, int minBack)
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
