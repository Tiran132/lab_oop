#include "CostInformation.h"


class CostRaitingInformation : CostInformation
{

private:
	int raiting;
	int countPosetiveReviews;
	int countNegativeReviews;

public:
	CostRaitingInformation(string url, int countDays, int currentCost, int currentCount, int raiting);

	int GetRaiting() const;

	int GetCountPosetiveReviews() const;

	int GetCountNegativeReviews() const;

	void Set_Raiting(int newRaiting);

	void Set_CountPosetiveReviews(int value);

	void Set_CountNegativeReviews(int value);

	virtual bool UpdateInfarmation(int newCost, int newCount) override;

	bool UpdateInfarmation(int newCost, int newCount, int newRaiting);

	virtual void Print() override;


	friend ostream& operator << (ostream& out, CostRaitingInformation& object);
};

