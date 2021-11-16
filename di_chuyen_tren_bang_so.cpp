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
		int a[m+2][n+2];
		memset(a, 0, sizeof(a));
		
		for ( int i = 1; i <= m; ++i)
			for ( int j = 1; j <= n; ++j)
				cin >> a[i][j];
		for ( int i = 1; i <= m; ++i)
			a[i][1] += a[i-1][1];
		for ( int i = 1; i <= n; ++i)
			a[1][i] += a[1][i-1];
		
		for ( int i = 2; i <= m; ++i) {
			for ( int j = 2; j <= n; ++j)
				a[i][j] = min(a[i][j] + a[i-1][j], a[i][j] + a[i][j-1]);
		}
		cout << a[m][n] << endl;
	}
	return 0;
}

