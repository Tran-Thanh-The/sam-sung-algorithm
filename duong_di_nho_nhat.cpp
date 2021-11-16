#include <bits/stdc++.h>
using namespace std;

int m, n;

int handle( int a[505][505]) {
	int b[m][n];
	b[0][0] = a[0][0];
	
	for ( int i = 1; i < n; ++i)
		b[0][i] = a[0][i] + b[0][i-1];
	for ( int i = 1; i < m; ++i)
		b[i][0] = a[i][0] + b[i-1][0];
		
	for ( int i = 1; i < m; ++i) {
		for ( int j = 1; j < n; ++j) {
			b[i][j] = min( b[i-1][j], b[i][j-1]);
			b[i][j] = min( b[i][j], b[i-1][j-1]);
			
			b[i][j] += a[i][j];
		}
	}
	
	return b[m-1][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		
		cin >> m >> n;
		int a[505][505];
		for ( int i = 0; i < m; ++i) 
			for ( int j = 0; j < n; ++j)
				cin >> a[i][j];
		
		cout << handle( a) << endl;		
	}
	return 0;
}

