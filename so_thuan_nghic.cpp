#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int db[1000][1000];
int Max = 0;

void handle() {
	memset( db, 0, sizeof(db));
	
	for ( int i = 0; i < n; i++)
		db[i][i] = 1;
	for ( int i = n-2; i >= 0; i--) {
		for ( int j = i+1; j < n; j++) {
			if ( s[i] == s[j]) {
				db[i][j] = 2 + db[i+1][j-1];
				if ( db[i][j] == j-i+1) {
					if ( db[i][j] > Max)
						Max = db[i][j];
				}
			}
			else {
				db[i][j] = max( db[i][j-1], db[i+1][j]);
				if ( db[i][j] == j-i+1) {
					if ( db[i][j] > Max)
						Max = db[i][j];
				}
			}
				
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		Max = 0;
		cin >> s;
		n = s.length();
		handle();
		cout << Max << endl;
	}
	return 0;
}


