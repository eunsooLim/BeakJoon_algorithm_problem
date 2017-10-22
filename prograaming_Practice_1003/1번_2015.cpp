#include <iostream>
#include<cstdio>
#include<vector> 
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
int mazesolve(int j, int k, int i) {

	int temp = maze[i][j][k];
	if (temp == 0) return -1;
	if (j == 7 && k == 7) return 1;
	if (checkmaze(temp, maze[i][j + xway[temp]][k + yway[temp]])) {
		mazesolve(j + xway[temp], k + yway[temp], i);
	}
	else return-1;


}

int main() {

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k<8; k++)
				cin >> maze[i][j][k];

		}
	}

	int check[10];
	for (int i = 0; i < testcase; i++) {
		check[i] = mazesolve(0, 0, i);
	}
	for (int i = 0; i < testcase; i++) {
		if (check[i] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
