#include <cstdio>
#include <iostream>
#include<vector>

using namespace std;



int main(int argc, char** argv) {

	int n;
	int d[12] = {0,1,2,4,7,13,24,44,-1,-1,-1,-1};

	cin >> n;
	int a;
	vector<int> li;
	for (int i = 0; i < n; i++) {
		cin >> a;
		li.push_back(a);

	}
	for (int i = 8; i < 12; i++) {
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
	
	for (int i = 0; i < n; i++) {
		cout << d[li[i]] << endl;
	}

}


