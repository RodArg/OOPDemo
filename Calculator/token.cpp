#include "token.h"
#include "std_lib_facilities.h"

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
