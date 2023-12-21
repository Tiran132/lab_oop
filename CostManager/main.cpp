#include <iostream>
#include "CostRaitingInformation.h"

using namespace std;

int main() {
	string url;
	int daysCount;
	int currentCost;
	int currentCount;


	try {
		CostRaitingInformation cost1{ "http://asd.asd", 10, 200, 10, 10 };
		CostInformation cost2{ "http://asd.asd", 10, 200, 10 };

		CostInformation* objects[2];

		objects[0] = (CostInformation*)&cost1;
		objects[1] = &cost2;

		if (cost1.UpdateInfarmation(210, 8, 8))
			cout << "Low count" << endl;

		if (cost1.UpdateInfarmation(200, 6, 9))
			cout << "Low count" << endl;

		if (cost1.UpdateInfarmation(190, 1, 10))
			cout << "Low count" << endl;

		cost1.Set_CountPosetiveReviews(2);

		(*objects[0]).Print();
		cout << endl;
		(*objects[1]).Print();
	}
	catch (const char* error_message) {
		cout << error_message << endl;
	}

	return 0;
}
