// Date cpp file - function implementations from header file
//program given by dr.poole

//libraries
#include "Date.h"

using namespace std;

Date::Date(int d , int m , int yyyy ) {
	setDate(d, m, yyyy);
}
Date::~Date() {}
void Date::setDate(int  d, int m, int yyyy) {
	day = d;
	month = m;
	year = yyyy;
}
 ostream& operator<<(ostream& output, Date d)
{
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
