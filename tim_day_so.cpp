#include <bits/stdc++.h>
using namespace std;

int division( int n, int k) {
	int h = n/k;
	for ( int i = 1; i <= h; ++i)
		if ( n/i == k)
			return i;
	return -1;
}

int handle( int a[], int k, int n) {
	int sum = 0;
	for ( int i = 0; i < n; ++i) {
		int tmp = division( a[i], k);
		if ( tmp == -1)
			return -1;
		sum += tmp;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	int min = 1e9;
	for ( int i = 0; i < n; i++) {
		cin >> a[i];
		min = ( min > a[i]) ? a[i] : min;
	}
		
	for ( int i = min; i >= 1; --i) {
		int res = handle( a, i, n);
		if ( res != -1) {
			cout << res;
			return 0;
		}
	}
	
	return 0;
}

