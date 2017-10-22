#include <iostream>
#include<cstdio>
#include<vector> 
#include <string>
using namespace std;


char change01(char a) {

	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return '1';
	else return '0';

}
int main() {

	string n ;
	
	
	vector<string> words;

	getline(cin, n);
	n = n + '\n';
	string word = "";
	char moum[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < n.length(); i++)
	{
		
		if (n[i] == ' ' || n[i] == '\n') {
			
			words.push_back(word);
			word = "";

		}
		else word = word + change01(n[i]);
		
	}
	

	int moumcout = 0;
	int threecount = 0;
	int temp;
	for (int i = 0; i < words.size(); i++) {

		
		temp = words[i].find("11");
		if (temp >= 0)  moumcout++;
		
		temp = words[i].find("000");
		if (temp >= 0 ) threecount++;
		
		
	}
	
	
	cout << moumcout << endl;
	cout<< threecount << endl;
	

	return 0;
}
