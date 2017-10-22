#include <cstdio>
#include <iostream>
#include<queue>

using namespace std;
queue<pair<int, int>> q1;
int n, k, min_depth;

void bfs() {
	int d;
	while (!q1.empty) {
		if (k == q1.front.first&& min_depth >= q1.front.second) {
			
			min_depth = q1.front.second; 
			q1.pop();
		}
		else {
			d= q1.front.second;
			q1.pop();
			if (n != 0)  q1.push(make_pair(n - 1, min_depth + 1)); 
			
			if(n<10000) q1.push(make_pair(n + 1, min_depth+1));

			if(n*2<100000)	q1.push(make_pair(n * 2, min_depth+1));
		}
	}
	
}

void main() {

	
	cin >> n>>k;
	if (n == 0){
		q1.push(make_pair(n + 1, 1));
		q1.push(make_pair(n * 2, 1));
	}
	else {
		q1.push(make_pair(n + 1, 1));
		q1.push(make_pair(n - 1, 1));
		q1.push(make_pair(n * 2, 1));
	}
	bfs();
	cout <<min_depth << endl;
	

}


