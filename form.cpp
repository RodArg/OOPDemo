#include "std_lib_facilities.h"

int main() {
	cout << "Enter the name of the person you want to write to.\n";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << ", I hope you've been well.";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?";
	int age;
	cin >> age;
	cout << "I heard you had a birthday and you are now " << age
		<< " years old!";
	if(age < 17)
		simple_error("You are young to be at NYU!");
	else if(age > 110)
		simple_error("It's great to see senior students around campus!");

}