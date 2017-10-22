#include <iostream>
#include<cstdio>
#include<string>
#include<vector> 
#include<stack>
using namespace std;

int maze[10][8][8];
int xway[5] = { 0,0,1,0,1 };
int yway[5] = { 0,1,0,1,0 };

bool checkmaze(int temp, int n) {
	if (temp == 1 || temp == 3) {
		if (n == 1 || n == 4) return true;
		else return false;
	}
	if (temp == 2 || temp == 4) {
		if (n == 2 || n == 3) return true;
		else return false;
	}

}
char mirror(char a) {
	if (a == '}') return '{';
	if (a == ')') return ')';
	if (a == ']') return '[';


}
int checkyn(string q) {
	stack<char> st;
	for (int i = 0; i < q.length(); i++) {
		if (q[i] == '{' || q[i] == '(' || q[i] == '[') {
			
			st.push(q[i]);
		}
		if (q[i] == '}' || q[i] == ')' || q[i] == ']') {
			if (mirror(st.top()) != q[i]) return -1;
			else st.pop();

		}
	}
	if (st.empty()) return 1;
	else return -1;

}
int main() {

	int testcase;
	cin >> testcase;
	
	vector<string> questions(testcase);
	vector<int> yesornot;
	for (int i = 0; i < testcase; i++) {
		cin >> questions[i];
		cout << questions[i] << endl;
		yesornot.push_back(checkyn(questions[i]));
	}
	for (int i = 0; i < yesornot.size(); i++) {
		if (yesornot[i] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
