#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int db[50][50];

int handle() {
	memset( db, 0, sizeof(db));
	
	for ( int i = 0; i < n; i++)
		db[i][i] = 1;
	for ( int i = n-2; i >= 0; i--) {
		for ( int j = i+1; j < n; j++) {
			if ( s[i] == s[j])
				db[i][j] = 2 + db[i+1][j-1];
			else {
				db[i][j] = max( db[i][j-1], db[i+1][j]);
			}
				
		}
	}
	return db[0][n-1];
}
// 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		cin >> s;
		n = s.length();
		cout << n - handle() << endl;
	}
	return 0;
}


