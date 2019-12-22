#include "Date.h"

Date::Date()
{
	
}

Date::~Date()
{

}

int Date::Get_day()
{
	return _day;
}

int Date::Get_month()
{
	return _month;
}

int Date::Get_year()
{
	return _year;
}

void Date::Set_day(int day)
{
	_day = day;
}

void Date::Set_month(int month)
{
	_month = month;
}

void Date::Set_year(int year)
{
	_year = year;
}

istream& operator>> (istream& is, Date& date)
{
	try
	{
		do {
			cout << "Nhap ngay: ";
			is >> date._day;
			if (is.fail())
				throw "Ngay nhap vao khong dung";
			cout << "Nhap thang: ";
			is >> date._month;
			if (is.fail())
				throw "Thang nhap vao khong dung";
			cout << "Nhap nam (bat dau tu nam 1900): ";
			is >> date._year;
			if (is.fail())
				throw "Nam nhap vao khong dung";
			cout << endl;
		} while (date.IsValidDate(date._day, date._month, date._year) == false);

		return is;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

ostream& operator<< (ostream& os, const Date& date)
{
	os << date._day << "/" << date._month << "/" << date._year;
	return os;
}

istream& inputDateFromFile(istream& is, Date& date)
{
	try
	{
		char c;
		do {
			is >> date._day;
			if (is.fail())
				throw "Ngay nhap vao khong dung";

			is >> c;

			is >> date._month;
			if (is.fail())
				throw "Thang nhap vao khong dung";

			is >> c;

			is >> date._year;
			if (is.fail())
				throw "Nam nhap vao khong dung";
		} while (date.IsValidDate(date._day, date._month, date._year) == false);

		return is;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

bool Date::IsLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

bool Date::IsValidDate(int day, int month, int year)
{
	if (year < 1900)
		return false;
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10: case 12:
		if (day > 0 && day <= 31)
		{
			return true;
			break;
		}
		else
		{
			return false;
			break;
		}
	case 4:case 6:case 9: case 11:
		if (day > 0 && day <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	case 2:
		if (IsLeapYear(year) == true)
		{
			if (day > 0 && day <= 29)
				return true;
			return false;
		}
		else
		{
			if (day > 0 && day <= 28)
				return true;
			return false;
		}
	default:
		return false;
	}
}

int Date::DayInMonth(int month, int year)
{
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10: case 12:
		return 31;
	case 4:case 6:case 9: case 11:
		return 30;
	case 2:
		if (IsLeapYear(year) == true)
			return 29;
		else
			return 28;
	default:
		return 0;
	}
}

void Date::PreviousDay(int& day, int& month, int& year)
{
	if (IsValidDate(day, month, year) == true)
	{
		day--;
		if (day == 0)
		{
			month--;
			if (month == 0)
			{
				year--;
				month = 12;
				day = 31;
			}
			else
				day = DayInMonth(month, year);
		}
	}
}

int Date::countDay(Date thatdate)
{
	int count = 0;
	int d = _day;
	int m = _month;
	int y = _year;
	if (IsValidDate(d, m, y) == true)
	{
		while (d != thatdate._day || m != thatdate._month || y != thatdate._year)
		{
			PreviousDay(d, m, y);
			count++;
		}
	}
	return count;
}
