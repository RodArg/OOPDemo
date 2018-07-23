#include "std_lib_facilities.h"

int main(){
	cout << "Please enter your expression" << endl;
	int lval = 0;
	int rval;
	char op;
	int res = 0;
	cin >> lval;
    if(!cin)
        error("Input error");
    for(char op; cin >> op;){
    	if(!cin){
                error("Input error");
            }
        if(op != 'x'){
            cin >> rval;
        }
        switch(op){
        		case '+':
        			lval += rval;
        			break;
        		case '-':
        			lval -= rval;
        			break;
        		case '*':
        			lval *= rval;
        			break;
        		case '/':
        			lval /= rval;
        			break;
        		default:
        			cout << lval << endl;
            }
	}
}
