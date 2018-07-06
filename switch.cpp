#include "std_lib_facilities.h"
int main(){
	int num;
	cout << "What's your favorite number 1-10?";
	cin >> num;
	switch(num){
	case 0: case 2: case 4: case 6: case 8: case 10:
		cout << "Nice and even";
		break;
	case 1: case 3: case 5: case 9:
		cout << "That's odd";
		break;
	case 7:
		cout << "Lucky!";
		break;
	}
}