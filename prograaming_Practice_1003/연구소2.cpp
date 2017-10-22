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

int go[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
bool check(int i, int j) {

	if (i < 0 || i >= n || j< 0 || j >= m) return false;
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
			temp[i][j] = v[i][j];
			if (v[i][j] == 2) q.push(make_pair(i, j));		
		}
	}
}

int main(int argc, char** argv) {

	cin >> n >> m;
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
	for (int a = 0; wall.size(); a++) {
		for (int b = a+1; b < wall.size(); b++) {
			for (int c = b+1; c < wall.size(); c++) {

				temp[wall[a].first][wall[a].second] = 1;
				temp[wall[b].first][wall[b].second] = 1;
				temp[wall[c].first][wall[c].second] = 1;
				r = bfs();
				if (max < r) max = r;
				clean();

			}
		}
	}
	cout << max << endl;


}


