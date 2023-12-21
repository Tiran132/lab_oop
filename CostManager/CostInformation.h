#include <string>
#include <iostream>
using namespace std;



enum ECostCategory { stable = 0, growing, falling, isMin, isMax};

const int LOW_COUNT = 2;

class CostInformation
{
    string url;

    int currentCount;

    int countDays;
    int currentDay;
    int* historicalCost;

public:
	CostInformation(string url, int countDays, int currentCost, int currentCount);

	CostInformation(string url, int currentCount);

	~CostInformation() {
		delete historicalCost;
	}

	bool UpdateInfarmation(int newCost, int newCount);


	bool IsLow() const;

	int GetMin() const;

	int GetMax() const;

	int GetAverage() const;

	ECostCategory GetDynamic() const;

	static string translateCategory(ECostCategory category);


	// Селекторы

	int GetCurrentCost() const;

	int GetCurrentCount() const;

	void Print();


	int operator [](int day);

	friend ostream& operator << (ostream& out, CostInformation& object);
};

