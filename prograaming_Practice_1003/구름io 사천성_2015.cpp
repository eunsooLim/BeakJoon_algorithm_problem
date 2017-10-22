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
	int visited[10][10];
	if (howtogo(a, b) < 0 || howtogo(c, d) < 0) return false;
	if (questions[a][b] * questions[c][d] == 0) return false;
	if (questions[a][b] != questions[c][d]) return false;
	

	int answer = questions[c][d];
	int temp;
	int nextx, nexty;
	visited[a][b] = 1;

	for (int i = 0; i < 4; i++) {
		
		nextx = a + x[i];
		nexty = b + y[i];
		temp = howtogo(nextx, nexty);

		if (temp == answer && nextx == c && nexty == d) return true;
		else if (temp == 0)// || temp == answer)
		{
			queue1.push({ nextx ,nexty ,i,0 });
			visited[nextx][nexty] = 1;
			//cout << "yes" << endl;
		}
		//else cout << "no" << endl;
	}
	int parent,depth,xx,yy;

	while (!queue1.empty()) {

		xx = queue1.front().x_a;
		yy = queue1.front().y_a;
		parent = queue1.front().parent_d;
		depth = queue1.front().depth;
		queue1.pop();
		
		for (int i = 0; i < 4; i++) {
		
			nextx = xx + x[i];
			nexty = yy + y[i];
			

			if (parent != i && depth == 2) continue;

			temp = howtogo(nextx, nexty);

						
			if (temp == answer && nextx == c && nexty == d) {
				//cout << "UUU" << endl;
				return true;
			}
			else if (temp == 0 )//|| temp == answer)
			{
				if (visited[nextx][nexty] != 1) {//여기서 체크를 해줘야 하므로 뒤에서 비짓해야함
					if (parent == i) {
						queue1.push({ nextx ,nexty ,i, depth });
						visited[nextx][nexty] = 1;
					}
					else {
						if (depth < 2) {
							queue1.push({ nextx ,nexty ,i, depth + 1 });
							visited[nextx][nexty] = 1;
						}
					}
				}
			}

		}
		
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
	vector<bool> answer;
	int a, b, c, d;
	int da[4];
	//bool answer[testcase];
	for (int i = 0; i < testcase; i++) {
		cin >> da[0] >> da[1] >> da[2] >> da[3];
		if (checkmaze(da[0] - 1, da[1] - 1, da[2] - 1, da[3] - 1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}



	return 0;
}
