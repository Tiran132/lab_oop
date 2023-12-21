#include <iostream>
#include "CostInformation.h"

using namespace std;

int main() {
	string url;
	int daysCount;
	int currentCost;
	int currentCount;

	/*cout << "Url: ";
	cin >> url;

	cout << "Days: ";
	cin >> daysCount;

	cout << "Cost: ";
	cin >> currentCost;

	cout << "Count: ";
	cin >> currentCount;*/




	try {
		//CostInformation cost1 { url, daysCount, currentCost, currentCount };
		CostInformation cost1{ "http://asd.asd", 10, 200, 10 };

		if (cost1.UpdateInfarmation(210, 8))
			cout << "Low count" << endl;

		if (cost1.UpdateInfarmation(200, 6))
			cout << "Low count" << endl;

		if (cost1.UpdateInfarmation(190, 1))
			cout << "Low count" << endl;

		cost1.Print();
		
	}
	catch (const char* error_message) {
		cout << error_message << endl;
	}

	return 0;
}
