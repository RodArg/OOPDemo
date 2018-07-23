#include "std_lib_facilities.h"

int main(){
		vector<string> text;
		vector<int> words;
		for(string word; cin >> word;){
		    text.push_back(word);
		}
		sort(text);
		for(string word:text)
		    cout << word << " ";
		cout << endl;
		string prev_word;
		prev_word = text[0];
		int word_num;
		word_num = 0;
		for(string curr_word:text){
		    if(curr_word == prev_word)
		        word_num++;
		    else{
		        cout << prev_word << ": " << word_num << endl;
		        word_num = 1;
		        prev_word = curr_word;
		    }
		}
		cout << prev_word << ": " << word_num << endl;
        keep_window_open();
		return 0;
}
