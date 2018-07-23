#include "std_lib_facilities.h"

int main(){
	vector <int> v;
	int i;
	while(cin >> i)
		v.push_back(i);
	
	for(int elem:v)
		cout << elem;
}