#include "std_lib_facilities.h"
int main(){
	
	char c = 'a';
	int i = 0;
	double d = 3.14;
	char* cp = &c;
	int* ip = &i;
	double* dp = &d;
	
	cout << "cp" << cp << " and its value is " << *cp << endl;
	cout << "ip" << ip << " and its value is " << *ip << endl;
	cout << "dp" << dp << " and its value is " << *dp << endl << endl;
	
	cout << "size of c is " << sizeof(c) << endl;
	cout << "size of i is " << sizeof(i) << endl;
	cout << "size of d is " << sizeof(d) << endl << endl;
	
	cout << "size of cp is " << sizeof(cp) << endl;
	cout << "size of ip is " << sizeof(ip) << endl;
	cout << "size of dp is " << sizeof(dp) << endl;

}
