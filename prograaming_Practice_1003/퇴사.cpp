#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, s;
	int T[15];
	int P[15];

	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> T[i]>>P[i];
	}
	int max = 0;
	for (int i = 1; i<(1 << n); i++) {
		
		int sum = 0;
		bool check = false;
		bool momcount = false;
		int mom = 0;
		for (int k = 0; k<n; k++) {
			if (i&(1 << k)) {
				if (momcount == false && (k + T[k] > n)) 
				{
					check = true;
					break;
				}
				if (momcount == true && (((mom + T[mom]) > k) || ((k + T[k]) > n )))
				{
					check = true;
					break;
				}
				mom = k;
				sum = sum + P[k];
				momcount = true;
			}
		}
		if (check==false && (sum > max)) {
			max=sum;
		}
	}
	cout << max << endl;
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_NUM 100

int price[MAX_NUM];
int day[MAX_NUM];
int dp[MAX_NUM];
int N, ret;

//재귀로 풀기
void solve(int now, int cost) {

for (int i = now + day[now]; i <= N; i++) {
solve(i, cost + price[i]);
}

if (now + day[now] > N + 1) return;

ret = max(ret, cost);
}

int main()
{
ios::sync_with_stdio(false);

cin >> N;

ret = 0;

for (int i = 1; i <= N; i++) {
cin >> day[i] >> price[i];
}

//for (int i = 1; i <= N; i++) {
//    solve(i, price[i]);
//}


// for문 , dp
for (int i = 1; i <= N; i++) {
dp[i] = price[i];
for (int j = 1; j < i; j++) {
if (day[j] + j > i) continue;
dp[i] = max(dp[i], dp[j] + price[i]);
}
}

for (int i = 1; i <= N; i++) {
if (day[i] + i > N + 1) continue;
ret = max(ret, dp[i]);
}

cout << ret << '\n';

}
[출처] 백준온라인 - 14501번 퇴사(삼성기출문제)|작성자 MOO


*/