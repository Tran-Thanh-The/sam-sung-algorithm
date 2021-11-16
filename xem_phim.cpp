#include <bits/stdc++.h>
using namespace std;

int ok[105][25005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	int a[n];
	memset(ok, 0, sizeof(ok));
		
	for ( int i = 1; i <= n; i++) {
		cin >> a[i];
		for ( int j = 1; j <= m; j++) {
			if ( a[i] <= j) {
				ok[i][j] = max(ok[i-1][j], ok[i-1][j-a[i]]+a[i]);
			}
			else {
				ok[i][j] = ok[i-1][j];
			}
		}
	}
	cout << ok[n][m];
	return 0;
}

