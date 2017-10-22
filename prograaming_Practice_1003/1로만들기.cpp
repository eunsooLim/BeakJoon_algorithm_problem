#include <cstdio>
#include <iostream>
#include<vector>

using namespace std;

int min(int a,int b,int c) {

	if (a <= b && a <= c) return a;
	if (b <= c && b <= a) return b;
	if (c <= a && c <= b) return c;

}
int min_min(int a, int b) {

	if (a <= b) return a;
	else return b;

}

int main(int argc, char** argv) {
	
	int n;
	vector<int> answer;
	
	cin >> n;
	answer.push_back(0);
	answer.push_back(0);
	


	for (int i = 2; i <= n; i++) {
		
		if (i % 3 == 0) {

			if (i % 2 == 0) { //3과 2로 나누어지는 경우 

				answer.push_back(min(answer[i / 3], answer[i / 2], answer[i - 1]) + 1);
			}
			else {
				answer.push_back(min_min(answer[i / 3], answer[i - 1]) + 1);
			}
		}
		else if (i % 2 == 0) {

			answer.push_back(min_min(answer[i / 2], answer[i - 1]) + 1);

		}
		else {
			answer.push_back(answer[i - 1] + 1);
		}
	}
	/*
	int d[1000010];

	d[1] = 0;
	for (int i = 2; i <= n; i++){
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i / 2] + 1 < d[i])
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i / 3] + 1 < d[i])
			d[i] = d[i / 3] + 1;
	}
	
	*/
	
	cout <<answer[n] << endl;
	
}


