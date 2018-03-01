#pragma once
#include <string>
#include <sstream>
using std::string;

class Date {
public:
	Date(int year, int month, int day);
	int getWeekdayByYearday() const;
	int year() const;
	int month() const;
	int day() const;
private:
	int _year;
	int _month;
	int _day;
};

struct OutEn {
	string operator()(const Date& d) {
		static const char* m[] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" };
		auto month = m[d.month()-1];
		string out;
		std::stringstream date;
		date << month << " ";
		switch (d.day())
		{
		case 1:
			date << "1st, ";
			break;
		case 2:
			date << "2nd, ";
			break;
		case 3:
			date << "3rd, ";
			break;
		default:
			date << d.day() << "th, ";			
			break;
		}		
		date << d.year();
		out = date.str();
		return out;

	}
};