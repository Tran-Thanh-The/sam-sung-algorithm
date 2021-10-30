#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int m, n;
		cin >> m >> n;
		int a[m+1][n+1];
		for ( int i = 1; i <= m; ++i) {
			for ( int j = 1; j <= n; ++j)
				cin >> a[i][j];
		}
		
		int res = 0;
		
		for ( int i = m-1; i >= 1; --i) {
			for ( int j = n-1; j >= 1; --j) {
				if ( a[i][j] == 1 && a[i+1][j+1] != 0 && a[i][j+1] != 0 && a[i+1][j] != 0) {
					int b = min( a[i+1][j+1], a[i][j+1]);
					b = min( b, a[i+1][j]);
					a[i][j] = b + 1;
					res = max( res, a[i][j]);
				}
			}
		}
		
		cout << res << endl;
	}
	return 0;
}

