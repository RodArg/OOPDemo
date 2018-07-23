#include "std_lib_facilities.h"

class Token{
	public:
		char kind;
		double value;
};

class Token_stream{
	public:
		Token get();
		void putback(Token t);
	private:
		Token buffer;
		bool full{false};	
};

void Token_stream::putback(Token t){
	buffer = t;
	full = true;
}

Token Token_stream::get(){
	if(full){
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch){
		case ';': 
		case 'q': 
		case '(':
		case '+':
		case '-':
		case '*':
		case '/':
		case ')':
			return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};	
		}
	}
}

Token_stream ts;

/* Grammar:
Expression
	Term
	Expression  + Term
	Expression - Term
Term
	Primary
	Term * Primary
	Term / Primary
Primary
	Number
		'(' Expression ')'
*/

double expression();
double term();
double primary();

double expression(){
	double left = term();
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term(){
	double left = primary();
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
				left /= primary();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double primary(){
	Token t = ts.get();
		switch(t.kind){
			case '(':{
				double number = expression();
				t = ts.get();
				if(t.kind != ')')
					error("')' expected");
				return number;
			}
			case '8':
				return t.value;
			default:
				error("primary expected");
		}
}

int main(){	
		double val = 0.0;
		while(cin){
			Token t = ts.get();
			//Debugging
				cout << "in main(), token " << t.kind << " with a value of " << t.value << endl;
			if(t.kind == 'q'){
				break;
			}
			if(t.kind == ';'){
				cout << " = " << val << endl;
			}
			else
				ts.putback(t);
			val = expression();
		}
	//Calculator
	/*
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
        if(op != 'x')
            cin >> rval;
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
	//Tokenizer
	Token t = ts.get();
	while(t.kind != 'q'){
		cout << "Got token " << t.kind << " with value " << t.value << endl;
		t = ts.get();
	}
//	for(Token token:tokens)
//		cout << "Token " << token.kind << " with value " << token.value << endl;
	*/
}
