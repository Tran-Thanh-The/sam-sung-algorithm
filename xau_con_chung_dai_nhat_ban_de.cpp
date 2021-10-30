#include <iostream>
#include <cstring>
using namespace std;

int ok[1004][1004];

int longestSubstring( string a, string b) {
	a = " " + a;
	b = " " + b;
	int m = a.length(), n = b.length();
	memset( ok, 0, sizeof(ok));
	int res = 0;
	
	for ( int i = 1; i <= m; i++) {
		for ( int j = 1; j <= n; j++) {
			if ( a[i] == b[j]) {
				ok[i][j] = 1 + ok[i-1][j-1];
			}
			else {
				ok[i][j] = max( ok[i-1][j], ok[i][j-1]);
			}
		}
	}
	return ok[m][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while( t--) {
		string a, b;
		cin >> a >> b;
		cout << longestSubstring( a, b) << endl;
	}
	
	return 0;
}

