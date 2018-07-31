#include "std_lib_facilities.h"
#include "date.h"
void test(){
	Date date1;
	cout << "Input a date in the format mm dd yyyy " << endl;
	cin >> date1;
	Date date2 = date1;
	Date date3 = date1;
	
	date2.add_month(1);
	date3.add_year(2);	
	
	cout << "Testing overloaded cout " << endl;
	cout << "cout << date1 << endl;" << endl;
	cout << date1 << endl;
	cout << "Testing printLongForm() " << endl;
	date1.printLongForm();
 	cout << "Testing adding days and wrapping around months. Adding 113 days to date1." << endl;
	date1.add_day(113);
	date1.printLongForm();
	
	cout << "Testing overloaded == " << endl;
	cout << "Date date2: " << date2 << endl;
	cout << "Date date3: " << date3 << endl;
	cout << "bool a = date2==date3;" << endl;
	cout << "bool b = date2!=date3;" << endl;
	bool a = date2==date3;
	bool b = date2!=date3;
	cout << "(0 = false, 1 = true) a is " << a << " while b is " << b << endl;
	cout << "Testing isLeapYear()" << endl;
	cout << "date2.isLeapYear() = " << date2.isLeapYear() << endl;
	cout << "date3.isLeapYear() = " << date3.isLeapYear() << endl;
}

int main(){
	while(true){
		try{
			test();
			return 0;
		}
		catch(...){
			cout << "Invalid input" << endl;
		}
	}
}
