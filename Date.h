#ifndef _DATE_
#define _DATE_

#include <iostream>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	~Date();

	int Get_day();
	int Get_month();
	int Get_year();

	void Set_day(int);
	void Set_month(int);
	void Set_year(int);

	friend istream& operator>> (istream&, Date&);
	friend ostream& operator<< (ostream&, const Date&);

	friend istream& inputDateFromFile(istream&, Date&);

	bool IsLeapYear(int);
	bool IsValidDate(int, int, int);
	int DayInMonth(int, int);
	void PreviousDay(int&, int&, int&);
	int countDay(Date);
};

#endif

