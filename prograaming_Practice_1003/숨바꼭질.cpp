#include <cstdio>
#include <iostream>
#include<queue>

using namespace std;
queue<pair<int, int> > q1;//> >nested에러가 남!!! 띄어쓰기 중요!!
int n, k;
int visited[100001];

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
			}
			if (m < 100000 && visited[m + 1] != 1)
			{
		
			q1.push(make_pair(m + 1, d + 1));
			visited[m + 1] = 1;
			}

			if (m * 2 <= 100000 && visited[m * 2] != 1)
			{
				q1.push(make_pair(m * 2, d + 1));
				visited[m * 2] = 1;
			}
		}
	}
	return -1;

}

int main() {


	cin >> n >> k;
	q1.push(make_pair(n, 0));
	visited[n] = 1;
	
	cout << bfs() << endl;

	return 0;
}
