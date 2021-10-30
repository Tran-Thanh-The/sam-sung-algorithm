#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[20], x[20];

void out() {
	for ( int i = 1; i <= k; i++) {
		cout << a[x[i]-1] << " ";
	}
	cout << endl;
}

void handle( int i) {
	for ( int j = x[i-1]+1; j <= n-k+i; j++) {
		x[i] = j;
		if ( i == k)
			out();
		else
			handle( i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int test;
	cin >> test;
	while( test--) {
		cin >> n >> k;
		for ( int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort( a, a+n);
		handle(1);
	}
	return 0;
}

