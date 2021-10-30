#include <bits/stdc++.h>
using namespace std;

int ok[1005][1005];

int longestSymmetricSubstring( string s) {
	int n = s.length();
	s = " " + s;
	memset( ok, 0, sizeof(ok));	
	int Max = 0;
	for ( int i = n; i >= 1; i--) {
		for ( int j = i; j <= n; j++) {
			if ( i == j)
				ok[i][j] = 1;
			else {
				if ( s[i] == s[j] && ((j-i-1) == ok[i+1][j-1] || j-i == 1)) {
					ok[i][j] = 2 + ok[i+1][j-1];
				}	
				else
					ok[i][j] = max( ok[i+1][j], ok[i][j-1]);
			}
		}
	}
//	for ( int i = 1; i <= n; i++) {
//		for ( int j = 1; j <= n; j++)
//			cout << ok[i][j] << " ";
//		cout << endl;
//	}
	
	return ok[1][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		string s;
		cin >> s;
		cout << longestSymmetricSubstring( s) << endl;
	}
	return 0;
}

