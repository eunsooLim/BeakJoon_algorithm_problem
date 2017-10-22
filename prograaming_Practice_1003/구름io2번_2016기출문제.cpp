#include <iostream>
#include<cstdio>
#include<vector> 
using namespace std;


int R(int n) {

	int result=0;
	while (n > 0) {
		result *= 10;
		result += n / 10;
		n = n / 10;	
	}
	return result;
	/*
	if (n >= 100)
	{
		return (n % 10) * 100 + R(n / 10);
	}
	else if (n >= 10) 
	{
		return (n % 10) * 10 + R(n / 10);
	}
	else 
	{
		return n;
	}
	*/
	
}
bool felindrom_check(int n) {

	if (n == R(n)) return true;
	else return false;

}
int F(int n,int depth) {

	if (depth == 3) return -1;
	n = n + R(n);
	if (felindrom_check(n)) {
		if (n >= 10000) return -1;
		return n;
	}
	else return F(n, depth + 1);

}


int main() {

	int n;
	cin >> n;
	cout<<F(n, 0)<<endl;

	return 0;
}
