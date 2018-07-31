#include "std_lib_facilities.h"
#include "date.h"

const int defYear = 1969;
const Month defMonth = Month(7);
const int defDay = 15;

ostream& operator << (ostream& os, const Date& d){
	return os << '('
		<< d.year() << ','
		<< d.month() << ','
		<< d.day() << ')';
}

istream& operator >> (istream& is, Date& date){
	int mm, dd, yyyy;
	is >> mm >> dd >> yyyy;
	date = Date(yyyy, Month(mm), dd);
	return is;
}

bool operator==(const Date& left, const Date& right){
	if(left.year() == right.year() &&
		left.month() == right.month() &&
		left.day() == right.day())
			return true;
	return false;
}

bool operator!=(const Date& left, const Date& right){
	if(left == right)
		return false;
	return true;
}

Date::Date(int yyyy, Month mm, int dd):y{yyyy}, m{mm}, d{dd}
{
	if(!isvalid())
		throw Invalid{}; //Invalid{};
}

Date::Date(): y(defYear), m(defMonth), d(defDay){};

void Date::add_day(int n){
	d += n;
	if(isLeapYear()){
		while(d > max_days_leap[int(m)]){
		d -= max_days[int(m)];
		add_month(1);
		}
	}
	else{
		while(d > max_days[int(m)]){
		d -= max_days[int(m)];
		add_month(1);
		}
	}
}
void Date::add_month(int n){
	int next = int(m) + n;
	int years = next / 12;
	if(next > 12){
		add_year(years);
		next %= 12;
	}
	if(next == 0)
		next = 12;
	m = Month(next);
}

void Date::add_year(int n){
	y += n;
}

void Date::printLongForm(){
	string mth;
	switch(m){
		case Month::jan:
			mth = "January";
			break;
		case Month::feb:
			mth = "February";
			break;
		case Month::mar:
			mth = "March";
			break;
		case Month::apr:
			mth = "April";
			break;
		case Month::may:
			mth = "May";
			break;
		case Month::jun:
			mth = "June";
			break;
		case Month::jul:
			mth = "July";
			break;
		case Month::aug:
			mth = "August";
			break;
		case Month::sep:
			mth = "September";
			break;
		case Month::oct:
			mth = "October";
			break;
		case Month::nov:
			mth = "November";
			break;
		case Month::dec:
			mth = "December";
			break;
	}
	cout << mth << " " << d << ", " << y << endl;
}
bool Date::isvalid(){
	if(int(m) < 1 || int(m) > 12){
		cout << "Month out of range " << endl; 
		return false;
	}
	if(isLeapYear())
		if(d > max_days_leap[int(m)]){
			cout << d << " exceeds maximum days in month " << max_days_leap[int(m)] << endl; 
			return false;	
		}
	else
		if(d > max_days[int(m)]){
			cout << d << " exceeds maximum days in month " << max_days[int(m)] << endl; 
			return false;	
		}
	return true;
}

bool Date::isLeapYear(){
	if((y%4) == 0 && (y%100) != 0 || (y%400) == 0)
		return true;
	return false;
}
