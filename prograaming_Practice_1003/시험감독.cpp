#include <cstdio>
#include <iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);
	/*5
10 9 10 9 10
7 2*/
	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	//setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);
	int n,b,c;
	int num = 0;
	vector<int> a;
	int test_case;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	cin >> b >> c;
	num = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] - b) <= 0) continue;
		if ((a[i] - b) % c > 0) {
			num += ((a[i] - b) / c) + 1;
		}
		else {
			num += ((a[i] - b) / c);
		}
	}
	cout << n + num << endl;

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}