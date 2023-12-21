#include <string>
#include <iostream>
using namespace std;



enum ECostCategory { stable = 0, growing, falling, isMin, isMax};

const int LOW_COUNT = 2;
//template <typename T, int LOW_COUNT>
class CostInformation
{
protected:
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

	virtual bool UpdateInfarmation(int newCost, int newCount);


	bool IsLow() const;

	int GetMin() const;

	int GetMax() const;

	int GetAverage() const;

	ECostCategory GetDynamic() const;

	static string translateCategory(ECostCategory category);


	// Селекторы

	int GetCurrentCost() const;

	int GetCurrentCount() const;

	virtual void Print();


	int operator [](int day) {
		return this->historicalCost[day - 1];
	}

	friend ostream& operator << (ostream& out, CostInformation& object) {
		out << "Url: " << object.url << endl;
		out << "Cost (Current): " << object.GetCurrentCost() << endl;
		out << "Count (Current): " << object.currentCount << endl;
		out << "Day (Current): " << object.currentDay << endl;
		out << "Dynamic: " << object.translateCategory(object.GetDynamic()) << endl;

		return out;
	}
};

