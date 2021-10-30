#include <bits/stdc++.h>
using namespace std;

int ok[1005][1005];

int longestCommonSubstring( string a, string b) {
	int m = a.length(), n = b.length();
	a = " " + a;
	b = " " + b;
	
	memset( ok, 0, sizeof(ok));
	
	for ( int i = 1; i <= m; ++i) {
		for ( int j = 1; j <= n; ++j) {
			if ( a[i] == b[j])
				ok[i][j] = ok[i-1][j-1] + 1;
			else
				ok[i][j] = max( ok[i-1][j], ok[i][j-1]);
		}
	}
	return ok[m][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		string a, b;
		cin >> a >> b;
		cout << longestCommonSubstring( a, b) << endl;
	}
	return 0;
}

