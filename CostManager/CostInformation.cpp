#include "CostInformation.h"

CostInformation::CostInformation(string url, int countDays, int currentCost, int currentCount) {
	if (currentCost < 0)
		throw "currentCost is less than 0!";

	if (currentCount < 0)
		throw "currentCount is less than 0!";
	
	if (countDays < 1)
		throw "countDays is less than 0!";

	this->url = url;
	this->currentCount = currentCount;
	this->historicalCost = new int[countDays];
	this->currentDay = 1;
	this->countDays = countDays;

	historicalCost[0] = currentCost;
}

bool CostInformation::UpdateInfarmation(int newCost, int newCount) {
	if (currentDay >= countDays)
		throw "Space in the array is complete!";

	currentDay++;

	historicalCost[currentDay - 1] = newCost;

	currentCount = newCount;

	return IsLow();
}

bool CostInformation::IsLow() const {
	return currentCount < LOW_COUNT;
}

int CostInformation::GetMin() const {
	if (currentDay == 0)
		throw "No historical Data!";

	int min = GetCurrentCost();
	for (int i = 0; i < currentDay; i++)
	{
		if (min > historicalCost[i])
			min = historicalCost[i];
	}

	return min;
}

int CostInformation::GetMax() const {
	if (currentDay == 0)
		throw "No historical Data!";

	int max = GetCurrentCost();
	for (int i = 0; i < currentDay; i++)
	{
		if (max < historicalCost[i])
			max = historicalCost[i];
	}

	return max;
}

int CostInformation::GetAverage() const {
	if (currentDay == 0)
		throw "No historical Data!";

	int sum = 0;
	for (int i = 0; i < currentDay; i++)
	{
		sum += historicalCost[i];
	}

	return sum / (currentDay);
}

ECostCategory CostInformation::GetDynamic() const {
	if (currentDay < 2)
		return stable;

	int lastCost = historicalCost[currentDay - 2];
	int currentCost = historicalCost[currentDay - 1];

	if (lastCost == currentCost)
		return stable;
	else if (lastCost < currentCost)
		return growing;
	else if (lastCost > currentCost)
		return falling;
	else if (currentCost == GetMin())
		return isMin;
	else if (currentCost == GetMax())
		return isMax;
}

string CostInformation::translateCategory(ECostCategory category) {
	switch (category)
	{
	case 0:
		return "stable";
	case 1:
		return "growing";
	case 2:
		return "falling";
	case 3:
		return "is min";
	case 4:
		return "is max";
	}
}

int CostInformation::GetCurrentCost() const {
	return historicalCost[currentDay - 1];
}

int CostInformation::GetCurrentCount() const {
	return currentCount;
}

void CostInformation::Print() {
	cout << "Url: " << url << endl;
	cout << "Cost (Current): " << GetCurrentCost() << endl;
	cout << "Count (Current): " << currentCount << endl;
	cout << "Day (Current): " << currentDay << endl;
	cout << "Dynamic: " << translateCategory(GetDynamic()) << endl;
}
