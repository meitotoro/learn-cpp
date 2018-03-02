#pragma once
#include <string>
#include <sstream>
#include <iostream>
using std::string;

class Date {
public:
	Date(int year, int month, int day);
	int getWeekdayByYearday() const;
	int year() const;
	int month() const;
	int day() const;
	template <class OutputPolicy=OutEn>
	void print() const{
		OutputPolicy out;
		string output = out(*this);
		std::cout<< output<<std::endl;
	}
	
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
		date << d.year()<<" ";
		int iweek = d.getWeekdayByYearday();
		string week[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		string w = week[iweek];
		date << w;
		out = date.str();
		return out;

	}
};
struct OutCh {
	string operator()(const Date& d) {
		std::stringstream date;
		date << d.year() << "年" << d.month() << "月" << d.day() << "日";
		int iweek = d.getWeekdayByYearday();
		string week[] = { "星期天","星期一","星期二","星期三","星期四","星期五","星期六" };
		string w = week[iweek];
		date << " " << w;
		string out = date.str();
		return out;
	}
};