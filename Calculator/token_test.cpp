#include <iostream>
#include "std_lib_facilities.h"
#include "token2.h"

int main(){
	vector<Token> tokens;
	Token_stream ts;
	
	for(Token t = ts.get(); t.kind != quit; t = ts.get)
		tokens.push_back(t);
	for(Token tok : tokens){
		if(tok.kind == number)
			cout << "A number token with val = " << tok.value << endl;
		else if(tok.kind == invalid)
			cout << "We received an invalid token with val = " << char(tok.value) << endl;
		else
			cout << "A token of kind " << tok.kind << endl;
	}
	return 0;
}
