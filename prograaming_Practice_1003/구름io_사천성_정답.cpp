#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {


	int m[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> m[i][j];

		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		bool flag = false;
		if (m[r1][c1] != m[r2][c2] || m[r1][c1] * m[r2][c2] == 0)
		{
			cout << "NO" << endl;
			continue;
		}
		int t1 = m[r1][c1];
		int t2 = m[r2][c2];
		m[r1][c1] = 0;
		m[r2][c2] = 0;

		for (int row = 0; row < 10; row++) {
		
			int cnt = 0;
			for (int r = min(r1, row); r <= max(r1, row); r++) {
				cnt += m[r][c1];

			}
			for (int r = min(r2, row); r <= max(r2, row); r++) {
				cnt += m[r][c2];

			}
			for (int c = min(c1, c2); c <= max(c1, c2); c++) {
				cnt += m[row][c];

			}
			if (cnt == 0) flag = true;
			
		
		}
		for (int col = 0; col < 10; col++) {
		
			int cnt = 0;
			for (int c = min(c1, col); c <= max(c1, col); c++) {
				cnt += m[r1][c];

			}
			for (int c = min(c2, col); c <= max(c2, col); c++) {
				cnt += m[r2][c];

			}
			for (int r = min(r1, r2); r <= max(r1, r2); r++) {
				cnt += m[r][col];

			}
			if (cnt == 0) flag = true;
	
		}
		if (flag) { cout << "YES" << endl; }
		else {
		
			m[r1][c1] = t1;
			m[r2][c2] = t2;
			cout << "NO" << endl;

		}

	}

	return 0;

}
