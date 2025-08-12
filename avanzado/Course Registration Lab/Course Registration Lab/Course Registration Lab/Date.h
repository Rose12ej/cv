//Date Class header file - stores and retrieves date info
//program given by dr.poole

#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>

class Date {
	friend std::ostream& operator<<(std::ostream&, Date);
public:
	Date(int d = 0, int m = 0, int yyyy = 0);
	~Date();
	void setDate(int  d, int m, int yyyy);
private:
	int day;
	int month;
	int year;
};

