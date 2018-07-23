#include "std_lib_facilities.h"

int main(){
		cout << "Enter recent temperatures and we will calculate their average: "
			<< endl;
		
		vector<double> temps;
		for(double temp; cin >> temp;)
			temps.push_back(temp);
		double total = 0.0;
		for(double temp : temps)
			total += temp;
		sort(temps);
		double median = temps[(int)(temps.size()/2)];
		cout << "Your median temperature for the last " << temps.size() 
			<< " days was " << median << endl;
		keep_window_open();
		return 0;
}