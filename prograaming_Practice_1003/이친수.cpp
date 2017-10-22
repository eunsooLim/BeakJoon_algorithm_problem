#include <cstdio>
#include <iostream>
#include<vector>

using namespace std;



int main(int argc, char** argv) {

	int n;
	long long d[91];
	d[0] = 0;
	d[1] = 1;
	cin >> n;
	if (n < 2) {
		cout << d[n] << endl;
		return 0;
	}
	for (int i = 2; i<=n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n]<< endl;
	return 0;
}


