
#include <cstdio>
#include <iostream>

using namespace std;


bool check(int i, int j, int checkm[3][2], int m, int n) {

	for (int k = 0; k < 3; k++) {
		if (i + checkm[k][0] < 0) return false;
		if (i + checkm[k][0] >= n) return false;
		if (j + checkm[k][1] < 0) return false;
		if (j + checkm[k][1] >= m) return false;

	}
	return true;
}

int main(int argc, char** argv) {

	int n, m;
	int num = 0;
	int tetromino[500][500];
	int mino[19][3];



	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tetromino[i][j];
		}
	}
	int checkm[3][2] = { { 0, 1 },{ 0,2 },{ 0,3 } };

	int a[19][3][2] = { { { 0, 1 },{ 0,2 },{ 0,3 } },{ { 1,0 },{ 2,0 },{ 3,0 } },{ { 0,1 },{ 1,0 },{ 1,1 } }
		,{ { 1,0 },{ 1,1 },{ 2,1 } } ,{ { 1,0 },{ 1,-1 },{ 2,-1 } },{ { 0,1 },{ 1,1 },{ 1,2 } } ,{ { 0,-1 },{ 1,-1 },{ 1,-2 } }
		,{ { 1,0 },{ 2,0 },{ 2,1 } } ,{ { 1,0 },{ 2,0 },{ 2,-1 } } ,{ { 1,0 },{ 2,0 },{ 0,1 } } ,{ { 1,0 },{ 2,0 },{ 0,-1 } }
		,{ { 1,0 },{ 1,1 },{ 1,2 } } ,{ { 1,0 },{ 1,-1 },{ 1,-2 } } ,{ { 1,0 },{ 0,1 },{ 0,2 } } ,{ { 0,-1 },{ 0,-2 },{ 1,0 } }
	,{ { 1,0 },{ 0,1 },{ 0,-1 } } ,{ { -1,0 },{ 1,0 },{ 0,1 } } ,{ { -1,0 },{ 0,-1 },{ 1,0 } } ,{ { -1,0 },{ 0,1 },{ 0,-1 } } };

	int sum = 0;
	int t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				if (check(i, j, a[k], m, n)) {
					t = tetromino[i][j] + tetromino[i + a[k][0][0]][j + a[k][0][1]] + tetromino[i + a[k][1][0]][j + a[k][1][1]] + tetromino[i + a[k][2][0]][j + a[k][2][1]];
					if (sum <= t) {
						sum = t;

					}
				}

			}
		}
	}
	cout << sum << endl;
	return 0;
}