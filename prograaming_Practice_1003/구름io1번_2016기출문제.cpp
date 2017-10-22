#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {

		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//정렬하는 법
		//오름차순으로 정렬한 것
	long long md = v[1] - v[0];
	long long minleft = 0;
	long long temp;
	for (int i = 1; i < n-1; i++) {
		temp = v[i + 1] - v[i];
		if (temp < md) {
			md = temp;
			minleft = i;

		}
	
	}
	cout << v[minleft] << " " << v[minleft + 1] << endl;
}





/*
#include <iostream>
#include<cstdio>
#include<vector> 
using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[10];

	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	
	}
	long long x_min;
	long long y_min;
	
	long long min;
	if (a[1] > a[0]) {
		min = a[1] - a[0];
		x_min = a[0];
		y_min = a[1];
	}
	else {
		x_min = a[1];
		y_min = a[0];
		min = a[0] - a[1];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) {
				if (min > (a[i] - a[j])) 
				{
					x_min = a[j];
					y_min = a[i];
					min = a[i] - a[j];
					
				}
				else if (min == (a[i] - a[j])) 
				{
					if (x_min + y_min > a[i] + a[j])
					{
						x_min = a[j];
						y_min = a[i];
					}
					
				
				}
			}
			else {//a[i]와a[j]의 거리가 0이거나 같거나, a[j]가 더 멀리 있는 경우
				if (min > (a[j] - a[i]))
				{
					x_min = a[i];
					y_min = a[j];
					min = a[j] - a[i];

				}
				else if (min == (a[j] - a[i]))
				{
					if (x_min + y_min > a[j] + a[i])
					{
						x_min = a[i];
						y_min = a[j];
					}

				}

			}
		}
	
	}
	
	cout << x_min <<" "<<y_min<< endl;
	
	return 0;
}
*/
