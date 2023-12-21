#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <Windows.h>
#define OPEN true
#define CLOSED false
using namespace std;

enum ETaskCategoru { bug = 1, newFunctionality, support };

class TaskInformation {
	string taskName;
	tm deadline;
	ETaskCategoru taskCategory;
	bool flagClosedOrOpen;
	string executor;
	unsigned int solutionTime;

public:
	TaskInformation(string& taskName, int& taskCategory, string dateTimeString) : flagClosedOrOpen(OPEN), solutionTime(0) {
		this->taskName = taskName;

		istringstream stringToTmConverter(dateTimeString);
		stringToTmConverter >> get_time(&deadline, "%d.%m.%Y");
		if (deadline.tm_mday < 0 || deadline.tm_mon < 0 || deadline.tm_year < 0)
			throw "����������� ���� ����� ������!";

		if (taskCategory < 1 || taskCategory > 3)
			throw "������������ ����� ���������!";
		this->taskCategory = static_cast<ETaskCategoru>(taskCategory);
	}
	~TaskInformation() {
	}

	inline tm GetDeadline() const {
		return deadline;
	}
	inline ETaskCategoru GetTaskCategory() const {
		return taskCategory;
	}
	inline bool GetFlagClosedOrOpen() const {
		return flagClosedOrOpen;
	}
	inline int GetSolutionTime() const {
		return solutionTime;
	}

	void SetExecutor(string& executor) {
		if (flagClosedOrOpen == CLOSED)
			throw "����� �������� ������ ������ �������� ������ � ������!";
		if (executor.length() == 0)
			throw "����������� ��� �����������!";
		this->executor = executor;
	}
	void SetSolutionTime(int solutionTime) {
		if (flagClosedOrOpen == CLOSED)
			throw "����� �������� ������ ������ �������� ������ � ������!";
		if (solutionTime < 0)
			throw "����������� ���������� ����� ���������� �� ������� �����!";
		this->solutionTime += solutionTime;
	}

	void ClosedFlag() {
		flagClosedOrOpen = CLOSED;
	}
	bool DeadlineCheck() {
		tm currentDayTime;
		chrono::system_clock::time_point nowDateTime = chrono::system_clock::now();
		time_t intermediateDayTime = chrono::system_clock::to_time_t(nowDateTime);
		localtime_s(&currentDayTime, &intermediateDayTime);
		if (currentDayTime.tm_year > deadline.tm_year) {
			return false;
		}
		if (currentDayTime.tm_year == deadline.tm_year &&
			currentDayTime.tm_mon > deadline.tm_mon) {
			return false;
		}
		if (currentDayTime.tm_year == deadline.tm_year &&
			currentDayTime.tm_mon == deadline.tm_mon &&
			currentDayTime.tm_mday > deadline.tm_mday) {
			return false;
		}
		return true;
	}
	void CoutTaskInformation() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "������������ ������: " << taskName << endl
			<< "���� �����: " << deadline.tm_mday << ":"
			<< deadline.tm_mon + 1 << ":" << deadline.tm_year + 1900 << endl;
		switch (taskCategory)
		{
		case bug:
			cout << "��������� ������: " << "Bag" << endl;
			break;
		case newFunctionality:
			cout << "��������� ������: " << "New functionality" << endl;
			break;
		case support:
			cout << "��������� ������: " << "Support" << endl;
			break;
		}
		if (flagClosedOrOpen) {
			cout << "������ ������: " << "Open" << endl
				<< "�����������: " << executor << endl;
		}
		else {
			cout << "������ ������: " << "Closed" << endl
				<< "�����������: " << executor << endl
				<< "����� ���������� �� ������� ������: " << solutionTime << endl;
		}
	}

};

