#include <bits/stdc++.h>
using namespace std;
int m, n;
bool a[105][105];
bool b[105][105];

void handle( int i, int j) {
	a[i][j] = false;
	if ( a[i][j+1]) {
		b[i][j+1] = true;
		handle( i, j+1);
	}
	if ( a[i+1][j+1]) {
		b[i+1][j+1] = true;
		handle( i+1, j+1);
	}
	if ( a[i+1][j]) {
		b[i+1][j] = true;
		handle( i+1, j);
	}
	if ( a[i+1][j-1]) {
		b[i+1][j-1] = true;
		handle( i+1, j-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while( t--) {
		cin >> m >> n;

		memset( b, false, sizeof(b));
		memset( a, false, sizeof(a));
		
		
		for ( int i = 1; i <= m; i++)
			for ( int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		
		int res = 0;
		for ( int i = 1; i <= m; i++) {
			for ( int j = 1; j <= n; j++) {
				if (a[i][j]) {
					b[i][j] = true;
					handle( i, j);
					res ++;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

