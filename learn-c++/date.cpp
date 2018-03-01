#include "date.h"

Date::Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
int Date::getWeekdayByYearday() const
{
	int iWeekDay = -1;
	int month = _month;
	int year = _year;
	if (1 == month || 2 == month)
	{
		month += 12;
		year--;
	}
	iWeekDay = (_day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

	return iWeekDay;
}


int Date::year() const
{
	return _year;
}

int Date::month() const
{
	return _month;
}

int Date::day() const
{
	return _day;
}
