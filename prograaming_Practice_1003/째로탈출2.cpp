#include <cstdio>
#include <iostream>
#include<queue>
#include<vector>

using namespace std;


int depthcheck[10][10][10][10];
int n, m;
char miro[10][10];
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,1,-1 };
typedef struct talchul {
	int x_red;
	int y_red;
	int x_blue;
	int y_blue;
	int depth;
}talchul;
talchul temp;
queue<talchul> queue1;

int bfs() {
	int ri, bi, ori, obi;
	int rj, bj, orj, obj;
	int nextdepth;
	while (!queue1.empty()) {
		if (queue1.front().depth == 10) return -1;
		ori = queue1.front().x_red;
		orj = queue1.front().y_red;
		obi = queue1.front().x_blue;
		obj = queue1.front().y_blue;
		nextdepth = queue1.front().depth + 1;

		queue1.pop();
		for (int k = 0; k < 4; k++) {
			int check = 0;
			ri = ori;
			rj = orj;
			bi = obi;
			bj = obj;
			if (((k == 0) && (bi >= ri)) || (k == 1 && ri >= bi) || (k == 2 && rj >= bj) || (k == 3 && bj >= rj))
			{
				while (miro[ri + x[k]][rj + y[k]] == '.' || miro[ri + x[k]][rj + y[k]] == 'O')
				{
					if (miro[ri + x[k]][rj + y[k]] == 'O')
					{
						check = 1;
						break;
					}
					ri = ri + x[k];
					rj = rj + y[k];
				}
				if (check != 1) miro[ri][rj] = 'R';

				while (miro[bi + x[k]][bj + y[k]] == '.' || miro[bi + x[k]][bj + y[k]] == 'O')
				{
					if (miro[bi + x[k]][bj + y[k]] == 'O')
					{
						check = 2;
						break;
					}
					bi = bi + x[k];
					bj = bj + y[k];

				}
				miro[ri][rj] = '.';
				if (check == 2) continue;

				if (check == 1) return nextdepth;



			}
			else if ((k == 0 && ri > bi) || (k == 1 && ri < bi) || (k == 2 && rj < bj) || (k == 3 && rj > bj))
			{

				while (miro[bi + x[k]][bj + y[k]] == '.' || miro[bi + x[k]][bj + y[k]] == 'O')
				{
					if (miro[bi + x[k]][bj + y[k]] == 'O')
					{
						check = 1;
						break;
					}
					bi = bi + x[k];
					bj = bj + y[k];

				}
				if (check == 1) continue;

				miro[bi][bj] = 'B';

				while (miro[ri + x[k]][rj + y[k]] == '.' || miro[ri + x[k]][rj + y[k]] == 'O')
				{
					if (miro[ri + x[k]][rj + y[k]] == 'O') return nextdepth;//정답인 경우
					ri = ri + x[k];
					rj = rj + y[k];
				}
				miro[bi][bj] = '.';

			}
			if (depthcheck[ri][rj][bi][bj] != 1) {

				temp = { ri,rj,bi,bj,nextdepth };
				queue1.push(temp);
				depthcheck[ri][rj][bi][bj] = 1;
			}
		}
	}
	return -1;
}

int main() {


	cin >> n >> m;
	char yu;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> yu;

			if (yu == 'R') {
				temp.x_red = i;
				temp.y_red = j;
				miro[i][j] = '.';
			}
			else if (yu == 'B') {
				temp.x_blue = i;
				temp.y_blue = j;
				miro[i][j] = '.';

			}
			else miro[i][j] = yu;
		}
	}

	temp.depth = 0;
	queue1.push(temp);
	depthcheck[temp.x_red][temp.y_red][temp.x_blue][temp.y_blue] = 1;

	cout << bfs() << endl;

}