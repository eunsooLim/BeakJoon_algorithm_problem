#include <iostream>
#include<cstdio>
#include<vector> 
#include<string>
#include<queue>

using namespace std;

int questions[10][10];

typedef struct datap {

	int x_a;
	int y_a;
	int parent_d;
	int depth;

}datap;

int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };

int howtogo(int x, int y) {
	if (x < 0 || y < 0) {
		//cout << x << " " << y << endl; 
		return -1;
	}
	if (x >= 10 || y >= 10) {
		//cout << x << " " << y << endl;
		return -1;
	}
	//cout << x << " " << y <<" - "<< questions[x][y]<< endl;
	return questions[x][y];

}
bool checkmaze(int a, int b, int c, int d) {

	queue<datap> queue1;
	int visited[10][10] = {};

	if (questions[a][b] == 0 || questions[c][d] == 0) return false;
	if (questions[a][b] != questions[c][d]) return false;
	int answer = questions[c][d];
	int temp;
	int nextx, nexty;
	visited[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		nextx = a + x[i];
		nexty = b + y[i];
		temp = howtogo(nextx, nexty);

		if (temp == answer && nextx == c && nexty == d) {
			questions[a][b] = 0;
			questions[c][d] = 0;
			return true;

		}
		else if (temp == 0)// || temp == answer)
		{
			queue1.push({ nextx ,nexty ,i,0 });
			visited[nextx][nexty] = 1;
			//cout << "yes" << endl;
		}
		//else cout << "no" << endl;
	}

	while (!queue1.empty()) {

		for (int i = 0; i < 4; i++) {
			nextx = queue1.front().x_a + x[i];
			nexty = queue1.front().y_a + y[i];
			temp = howtogo(nextx, nexty);
			if (temp == answer && nextx == c && nexty == d) {
				if (queue1.front().depth < 2) {
					questions[a][b] = 0;
					questions[c][d] = 0;
					return true;
				}
				else {
					if (queue1.front().parent_d == i) {
						questions[a][b] = 0;
						questions[c][d] = 0;
						return true;
					}
					}//cout << "UUU" << endl;
			}
			else if (temp == 0)//|| temp == answer)
			{
				if (visited[nextx][nexty] != 1) {
					if (queue1.front().parent_d == i) {
						queue1.push({ nextx ,nexty ,i,queue1.front().depth });
						visited[nextx][nexty] = 1;
					}

					else
						if (queue1.front().depth < 2)
						{
							queue1.push({ nextx ,nexty ,i,queue1.front().depth + 1 });
							visited[nextx][nexty] = 1;
						}
					
					//cout << "yes" << endl;
				}
			}
			//else cout << "no" << endl;

		}
		queue1.pop();
	}
	return false;
}

int main() {

	int testcase;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> questions[i][j];
		}
	}
	cin >> testcase;
	vector<bool> answer(testcase);
	int a, b, c, d;
	int da[1000][4];
	for (int i = 0; i < testcase; i++) {
		cin >> da[i][0] >> da[i][1] >> da[i][2] >> da[i][3];

	}
	for (int i = 0; i < testcase; i++) {

		answer[i] = checkmaze(da[i][0] - 1, da[i][1] - 1, da[i][2] - 1, da[i][3] - 1);
	}
	for (int i = 0; i<testcase; i++) {
		if (answer[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}



	return 0;
}
