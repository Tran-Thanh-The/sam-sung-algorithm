#include <bits/stdc++.h>
using namespace std;
int m, n;

void handle( char a[][1000], int b[][1000], int count, int i, int j) {
	if ( j < n-1 && a[i][j+1] == '#') {
		b[i][j+1] = count;
		handle( a, b, count, i, j+1);
	}
	if ( i < m-1 && a[i+1][j] == '#') {
		b[i+1][j] = count;
		handle( a, b, count, i+1, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	char a[m][1000];
	int b[m][1000];
	memset( b, 0, sizeof(b));
	
	for ( int i = 0; i < m; i++)
		for ( int j = 0; j < n; j++)
			cin >> a[i][j];
	int res = 1;
	for ( int i = 0; i < m; i++) {
		for ( int j = 0; j < n; j++) {
			if ( a[i][j] == '#' && b[i][j] == 0) {
				b[i][j] = res;
				handle( a, b, res, i, j);
				res ++;
			}
		}
	}
	cout << res-1;
	return 0;
}

