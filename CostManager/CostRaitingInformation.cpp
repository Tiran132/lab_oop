#include "CostRaitingInformation.h"

CostRaitingInformation::CostRaitingInformation(string url, int countDays, int currentCost, int currentCount, int raiting) :CostInformation(url, countDays, currentCost, currentCount) {
	if (raiting < 0)
		throw "raiting is less than 0!";

	this->raiting = raiting;
	this->countNegativeReviews = 0;
	this->countPosetiveReviews = 0;
}

int CostRaitingInformation::GetRaiting() const {
	return raiting;
}

int CostRaitingInformation::GetCountPosetiveReviews() const {
	return countPosetiveReviews;
}

int CostRaitingInformation::GetCountNegativeReviews() const {
	return countNegativeReviews;
}

void CostRaitingInformation::Set_Raiting(int newRaiting) {
	raiting = newRaiting;
}

void CostRaitingInformation::Set_CountPosetiveReviews(int value) {
	countPosetiveReviews = value;
}

void CostRaitingInformation::Set_CountNegativeReviews(int value) {
	countNegativeReviews = value;
}

bool CostRaitingInformation::UpdateInfarmation(int newCost, int newCount) {
	if (currentDay >= countDays)
		throw "Space in the array is complete!";

	currentDay++;

	historicalCost[currentDay - 1] = newCost;

	currentCount = newCount;
	raiting = 5;

	return IsLow();
}

bool CostRaitingInformation::UpdateInfarmation(int newCost, int newCount, int newRaiting) {
	if (currentDay >= countDays)
		throw "Space in the array is complete!";

	currentDay++;

	historicalCost[currentDay - 1] = newCost;

	currentCount = newCount;
	raiting = newRaiting;

	return IsLow();
}

void CostRaitingInformation::Print() {
	cout << "Url: " << url << endl;
	cout << "Cost (Current): " << GetCurrentCost() << endl;
	cout << "Count (Current): " << currentCount << endl;
	cout << "Day (Current): " << currentDay << endl;
	cout << "Dynamic: " << translateCategory(GetDynamic()) << endl;
	cout << "Raiting: " << raiting << endl;
	cout << "Posetive reviews: " << countPosetiveReviews << endl;
	cout << "Negative reviews: " << countNegativeReviews << endl;
}

ostream& operator << (ostream& out, CostRaitingInformation& object) {
	out << "Url: " << object.url << endl;
	out << "Cost (Current): " << object.GetCurrentCost() << endl;
	out << "Count (Current): " << object.currentCount << endl;
	out << "Day (Current): " << object.currentDay << endl;
	out << "Dynamic: " << object.translateCategory(object.GetDynamic()) << endl;
	out << "Raiting: " << object.raiting << endl;
	out << "Posetive reviews: " << object.countPosetiveReviews << endl;
	out << "Negative reviews: " << object.countNegativeReviews << endl;

	return out;
}