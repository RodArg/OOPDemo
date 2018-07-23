#include "std_lib_facilities.h"
#include "token.h"
//#include "parser.h"

const char prompt = '>';
const string result = "= ";

double expression(Token_stream ts);
double term(Token_stream ts);
double primary(Token_stream ts);

double expression(Token_stream ts){
	double left = term(ts);
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '+':
				left += term(ts);
				t = ts.get();
				break;
			case '-':
				left -= term(ts);
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term(Token_stream ts){
	double left = primary(ts);
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
				if(primary() == 0)
					error("Error: divide by 0");
				left /= primary(ts);
				t = ts.get();
				break;
			case '%':
				if(primary() == 0)
					error("Error: mod by 0");
				left = fmod(left, primary(ts));
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double primary(Token_stream ts){
	Token t = ts.get();
		switch(t.kind){
			case '(':{
				double number = expression(ts);
				t = ts.get();
				if(t.kind != ')')
					error("')' expected");
				return number;
			}
			case '-':
				return -primary(ts);
			case '+':
				return primary(ts);
			case number:
				return t.value;
			default:
				error("primary expected");
		}
}

void clean_up_mess(){
	ts.ignore(print);
}

void calculate(Token_stream ts){
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
	Token_stream ts;
	calculate(ts);
}
