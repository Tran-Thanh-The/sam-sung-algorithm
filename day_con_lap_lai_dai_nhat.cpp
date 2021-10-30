#include <bits/stdc++.h>
using namespace std;

int ok[1005][1005];

int longestRepeatingSubstring( string s) {
	memset( ok, 0, sizeof(ok));
	s = " " + s;
	int n = s.length();
	
	for ( int i = 1; i < n; i++) {
		for ( int j = 1; j < n; j++) {
			if ( s[i] == s[j] && i != j )
				ok[i][j] = 1 + ok[i-1][j-1];
			else 
				ok[i][j] = max( ok[i-1][j], ok[i][j-1]);
		}
	}
	return ok[n-1][n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << longestRepeatingSubstring( s) << endl;
	}
	return 0;
}

