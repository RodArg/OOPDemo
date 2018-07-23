#include "parser.h"
#include "std_lib_facilities.h"
#include "token.h"

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
				if(primary() == 0)
					error("Error: divide by 0");
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
			default:
				error("primary expected");
		}
}
