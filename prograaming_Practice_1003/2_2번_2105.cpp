#include <iostream>
#include<cstdio>
#include<string>
#include<vector> 
#include<stack>
using namespace std;

char mirror(char a) {
	if (a == '}') return '{';
	if (a == ')') return '(';
	if (a == ']') return '[';


}
vector<int> checkyn(string q) {
	stack<pair<char, int>> st;
	vector<int> answer;
	for (int i = 0; i < q.length(); i++) {
		
		if (q[i] == '{' || q[i] == '(' || q[i] == '[') {
			if (st.empty()) {
				st.push(make_pair(q[i], 0));
				answer.push_back(0);
			}
			else {
				st.push(make_pair(q[i], st.top().second + 1));
				answer.push_back(st.top().second);
			}
		}
		else if (q[i] == '}' || q[i] == ')' || q[i] == ']') {
			if (st.empty()) {
				answer.push_back(0);
				return answer;
			}

			if (st.top().first != mirror(q[i])) {
				answer.clear();
				answer.push_back(st.top().second + 1);
				return answer;

			}
			else {
				answer.push_back(st.top().second);
				st.pop();
			}
		}
		else {
			if (st.empty()) {
				answer.push_back(0);

			}
			else
			 answer.push_back(st.top().second + 1);

		}
	}
	if (st.empty()) {

		return answer;

	}
	else {
		answer.clear();
		answer.push_back(-1);
		return answer;
	}

}
int main() {

	int testcase;
	cin >> testcase;

	vector<string> questions(testcase);
	vector<vector<int>> yesornot;
	for (int i = 0; i < testcase; i++) {
		cin >> questions[i];
		yesornot.push_back(checkyn(questions[i]));
	}
	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < yesornot[i].size(); j++) {
			cout << yesornot[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
