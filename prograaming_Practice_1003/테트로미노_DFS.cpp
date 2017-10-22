#include <cstdio>
#include <iostream>

using namespace std;

int result;
int tetromino[500][500];

int n, m;
int go[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
int nexti, nextj;

bool check(int i, int j, int checkm[3][2]) {

	for (int k = 0; k < 3; k++) {
		if (i + checkm[k][0] < 0) return false;
		if (i + checkm[k][0] >= n) return false;
		if (j + checkm[k][1] < 0) return false;
		if (j + checkm[k][1] >= m) return false;

	}
	return true;
}

void dfs_algorithm(int ci, int cj, int mom,int dad,int depth, int sum)
{
	if (depth == 3) {
		if (sum >= result) result = sum;
		return;
	}
	for (int kk = 0; kk < 4; kk++) {
		nexti = ci + go[kk][0];
		nextj = cj + go[kk][1];
		if (mom == nexti && dad == nextj) continue;
		
		if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m)	continue;
		
		dfs_algorithm(nexti, nextj,ci,cj, depth + 1, sum + tetromino[nexti][nextj]);
		

	}

}

int main(int argc, char** argv) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tetromino[i][j];
		}
	}
	
	int a[4][3][2] = { { { 1,0 },{ 0,1 },{ 0,-1 } } ,{ { -1,0 },{ 1,0 },{ 0,1 } } ,{ { -1,0 },{ 0,-1 },{ 1,0 } } ,{ { -1,0 },{ 0,1 },{ 0,-1 } } };

	int t;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
		
			dfs_algorithm(i, j, i,j,0, tetromino[i][j]);

			for (int k = 0; k < 4; k++) {
				if (check(i, j, a[k])) {
					t = tetromino[i][j] + tetromino[i + a[k][0][0]][j + a[k][0][1]] + tetromino[i + a[k][1][0]][j + a[k][1][1]] + tetromino[i + a[k][2][0]][j + a[k][2][1]];
					if (result <= t) result = t;
						
				}

			}
		}
	}
	cout << result << endl;
	return 0;
}


