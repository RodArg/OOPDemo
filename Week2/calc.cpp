#include "std_lib_facilities.h"

class Token{
	public:
		char kind;
		double value;
};

void p_token(Token t){
	cout << "Token.kind = " << t.kind << endl;	
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
				break;
			case '-':
				left -= term();
				break;
			default:
				return left;
		}
	}
}

double term(){
	return primary();
}

double primary(){
	Token t = ts.get();
	cout << "Primary token = " << t.value << endl;
	return t.value;
}

int main(){
//	Token t = ts.get();
//	while(t.kind != 'q'){
//		cout << "Got token " << t.kind << " with value " << t.value << endl;
//		//test putback, if we get an infinite loop with the same value then putback works
//		//ts.putback(t);
//		t = ts.get();
//	}
	
		double val = 0.0;
		while(cin){
			Token t = ts.get();
			//Debugging
				cout << "in main(), token " << t.kind << " with a value of " << t.value << endl;
			if(t.kind == 'q'){
				cout << "breaking" << endl;
				break;
			}
			if(t.kind == ';'){
				p_token(t);
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

Token get_token(){
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
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':{
			cin .putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};	
		}
		default:
			return Token{'i', double(ch)};
	}
}
