#include "std_lib_facilities.h"

const char number = '8';
const char print = ';';
const char quit = 'q';
const char prompt = '>';
const string result = "= ";

class Token{
	public:
		char kind;
		double value;
};

class Token_stream{
	public:
		Token get();
		void putback(Token t);
		void ignore(char c);
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
		case print: 
		case quit: 
		case '(':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ')':
			return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{number, val};	
		}
	}
}

void Token_stream::ignore(char c){
	if(full && c == buffer.kind){
		full = false;
		return;
	}
	full = false;
	
	char ch = 0;
	while(cin >> ch)
		if(ch == c)
			return;
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
	'+' Expression
	'-' Expression
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
				if(primary() == 0){
					//
					cout << "primary = " << primary() << endl;
					//
					error("Error: divide by 0");
				}
				left /= primary();
				t = ts.get();
				break;
			case '%':
				if(primary() == 0)
					error("Error: mod by 0");
				left = fmod(left, primary());
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
			case '-':
				return -primary();
			case '+':
				return primary();
			case number:
				return t.value;
			case print:
				if(t.kind != ')')
					ts.putback(t);
				break;
			default:
				cout << "primary default last token " << t.kind << endl;
				error("primary expected");
		}
}

void clean_up_mess(){
	ts.ignore(print);
}

void calculate(){
	while(cin){
		cout << prompt;
		try{
			Token t = ts.get();
			//Token Debugging
				//cout << "in main(), token " << t.kind << " with a value of " << t.value << endl;
			while(t.kind == print)
				t = ts.get();
			if(t.kind == quit)
				return;
			ts.putback(t);
			cout << result << expression() << endl;
		}
		catch(...){
			cerr << "Something went wrong" << endl;
			clean_up_mess();
		}
	}
}

int main(){	
		calculate();
}
