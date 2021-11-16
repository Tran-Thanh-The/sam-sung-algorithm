#include <bits/stdc++.h>
using namespace std;

int ok[1005][1005];

void solve() {
	int n, w;
	cin >> n >> w;
	int a[n+1], b[n+1];
	for ( int i = 1; i <= n; i++)
		cin >> a[i];
	for ( int i = 1; i <= n; i++)
		cin >> b[i];
	memset(ok, 0, sizeof(ok));
		
	for ( int i = 1; i <= n; i++) {
		for ( int j = 1; j <= w; j++) {
			if ( a[i] <= j) {
				ok[i][j] = max(ok[i-1][j], ok[i-1][j-a[i]]+b[i]);
			}
			else {
				ok[i][j] = ok[i-1][j];
			}
		}
	}
	cout << ok[n][w] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		solve();
	}
	return 0;
}

