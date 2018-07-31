#include "std_lib_facilities.h"

struct Reading {
	int num;
	int like;
	int follow;
};

int main(){
	cout << "Please enter the name of the input file: ";
	string iname;
	cin >> iname;
	ifstream ist {iname};
	if(!ist)
		error("Can't open input file ", iname);
		
	string oname;
	cout << "Please enter the name of the output file: ";
	cin >> oname;
	ofstream ost {oname};
	if(!ost)
		error("Can't open output file ", oname);
	vector<Reading> order;
	int num;
	char c1;
	int like;
	char c2;
	int follow;
		//
		cout << ist << endl;
	while(ist >> num >> c1 >> like >> c2 >> follow){
		cout << "I'm in a while loop " << endl;
		if(follow < 0)
			error("Follow out of range");
		order.push_back(Reading{num, like, follow});
	}
		//
		cout << order.size() << endl;
	for(int i = 0; i < order.size(); ++i){
		ost << order[i].num << "\t" << order[i].like << 
		 "\t" << order[i].follow << endl;
	}
}
