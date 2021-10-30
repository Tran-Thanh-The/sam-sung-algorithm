#include <bits/stdc++.h>
using namespace std;

int ok[1005][1005];

int longestSymmetricSubstring( string s) {
	memset( ok, 0, sizeof(ok));
	int n = s.length();
	s = " " +  s;
	
	for ( int i = n; i >= 1; --i) {
		for ( int j = i; j <= n; ++j) {
			if ( i == j)
				ok[i][j] = 1;
			else {
				if ( s[i] == s[j])
					ok[i][j] = 2 + ok[i+1][j-1];
				else
					ok[i][j] = max( ok[i+1][j], ok[i][j-1]);
			}
		}
	}
	
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
		
		cout << s.length() - longestSymmetricSubstring( s) << endl;
	}
	return 0;
}

