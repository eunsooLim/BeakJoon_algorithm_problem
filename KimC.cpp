#include <cstdio>
#include <iostream>
#include<queue>


using namespace std;
int n, in;
int pushback = 0;
int color = 4;
int Kim[200][200] = { 0, };
int level[201] = { 0, };
bool check(int x, int y, int z) {

	if (Kim[x][y] == Kim[z][y]) {
		return false;
	}
	else return true;

}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	int T;
	int test_case;


	queue<pair<int, int> > q;
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

		cin >> n;
		cin >> in;
		int x, y;
		for (int i = 0; i < in; i++) {
			cin >> x >> y;
			Kim[x - 1][y - 1] = 1;
			Kim[y - 1][x - 1] = 1;


		}

		int breakcheck = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Kim[i][j] == 1) {
					q.push(make_pair(i, j));
					Kim[i][j] = color;
					breakcheck = 1;
					pushback++;
				}

			}
			if (breakcheck == 1) {
				break;
			}
		}//ù ������ �����͵��� ť�� ����!
		breakcheck = 0;
		//color = 5;
		while (!q.empty()) {

			int d1 = q.front().first;
			int d2 = q.front().second;//
			q.pop();
			if (q.empty()) {
				pushback = 1;
			}
			for (int k = 0; k < n; k++) {
				if (Kim[d2][k] == 1) {
					if (d1 == k) {
						continue;
					}
					else {
						if (check(k, d2, d1)) {
							q.push(make_pair(d2, k));
							if (Kim[d1][d2] == 4) {
								Kim[d2][k] = 5;
							}
							else {
								Kim[d2][k] = 4;
							}



						}
						else
							breakcheck = 1;
					}
				}
			}
			if (breakcheck == 1) break;
			if (pushback == 1) {
				if (color == 5)color = 4;
				else color = 5;
				pushback = 0;
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		if (breakcheck == 1) {
			cout << 0 << endl;
		}
		else cout << 1 << endl;

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}