#include <cstdio>
#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int v[8][8];
int temp[8][8];
queue<pair<int, int>> q;
vector<pair<int, int>> wall;

int go[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool check(int i, int j) {

	if (i < 0 || i >= n || j< 0 || j>= m) return false;
	if (temp[i][j] == 0) return true;
	else return false;

}
int bfs() {
	
	int count = 0;
	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (check(x + go[i][0], y + go[i][1])) {
				temp[x + go[i][0]][y + go[i][1]] = 2;
				q.push(make_pair(x + go[i][0], y + go[i][1]));
			}
		}		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) count++;
		}
	}
	return count;
}
void clean() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2) {
				if (v[i][j] != 2) temp[i][j] = 0;
				else if(v[i][j] == 2) q.push(make_pair(i, j));
			}	
		}
	}
}

int main(int argc, char** argv) {

	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			temp[i][j] = v[i][j];
			if (temp[i][j] == 2) q.push(make_pair(i, j));
			if (temp[i][j] == 0) wall.push_back(make_pair(i, j));

		}
	}
	int max = 0;
	int r;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			if (temp[a][b] == 1 || temp[a][b] == 2) continue;
			temp[a][b] = 1;
			for (int c = a; c < n; c++) {
				for (int d = 0; d < m; d++) {
					if (c == a && d <= b) continue;
					if (temp[c][d] == 1|| temp[c][d] == 2) continue;
					temp[c][d] = 1;

					for (int e = c; e < n; e++) {
						for (int f = 0; f < m; f++) {
							if (e == c && f <= d) continue;
							if (temp[e][f] == 1|| temp[e][f] == 2) continue;
							temp[e][f] = 1;
							r = bfs();
							
							if (max < r) {
								max = r;
							}
							clean();
							temp[e][f] = 0;

						}
					}
					temp[c][d] = 0;

				}
			}
			temp[a][b] = 0;

		}
	}
	cout << max << endl;
	

}


