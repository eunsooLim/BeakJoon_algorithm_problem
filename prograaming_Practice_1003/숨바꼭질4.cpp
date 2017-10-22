#include <cstdio>
#include <iostream>
#include<queue>
#include<vector>

using namespace std;
queue<pair<int, int> > q1;//> >nested에러가 남!!! 띄어쓰기 중요!!
int n, k;
int visited[100001];
vector<int> visitway[100001];

int bfs() {
	int d;
	int m;

	while (!q1.empty()) {
		if (k == q1.front().first)
			return  q1.front().second;

		else {
			d = q1.front().second;
			m = q1.front().first;
			q1.pop();
			if (m - 1 >= 0 && visited[m - 1] != 1) {

				q1.push(make_pair(m - 1, d + 1));
				visited[m - 1] = 1;
				visitway[m - 1].push_back(m);
				visitway[m - 1].push_back(m - 1);

			}
			if (m < 100000 && visited[m + 1] != 1)
			{

				q1.push(make_pair(m + 1, d + 1));
				visited[m + 1] = 1;
				visitway[m + 1].push_back(m);
				visitway[m + 1].push_back(m + 1);

			}

			if (m * 2 <= 100000 && visited[m * 2] != 1)
			{
				q1.push(make_pair(m * 2, d + 1));
				visited[m * 2] = 1;
				visitway[m * 2].push_back(m);
				visitway[m * 2].push_back(m * 2);

			}
		}
	}
	return -1;

}

int main() {


	cin >> n >> k;
	q1.push(make_pair(n, 0));
	visited[n] = 1;
	visitway[n].push_back(n);
	visitway[n].push_back(n);

	cout << bfs() << endl;
	int momcount = k;
	vector<int> answer;
	answer.push_back(visitway[momcount][1]);

	while (momcount != n) {

		momcount = visitway[momcount][0];
		answer.push_back(momcount);


	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}