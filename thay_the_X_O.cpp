#include <bits/stdc++.h>
using namespace std;

int m, n;
char a[30][30];

void handle( int i, int j) {
	a[i][j] = '1';
	
	if ( a[i+1][j] == 'O')
		handle( i+1, j);
	if ( a[i-1][j] == 'O')
		handle( i-1, j);
	if ( a[i][j-1] == 'O')
		handle( i, j-1);
	if ( a[i][j+1] == 'O')
		handle( i, j+1);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		
		memset( a, 'X', sizeof(a));
		cin >> m >> n;
		for ( int i = 1; i <= m; ++i) 
			for ( int j = 1; j <= n; ++j)
				cin >> a[i][j];
		
		for ( int i = 1; i <= n; ++i) {
			if ( a[1][i] == 'O')
				handle(1, i);
			if ( a[m][i] == 'O')
				handle(m, i);
		}
		
		for ( int i = 1; i <= m; ++i) {
			if ( a[i][1] == 'O')
				handle(i, 1);
			if ( a[i][n] == 'O')
				handle(i, n);
		}
		
		for ( int i = 1; i <= m; ++i) {
			for ( int j = 1; j <= n; ++j) {
				if ( a[i][j] == '1')
					cout << "O ";
				else
					cout << "X ";
			}
			cout << endl;
		}
	}
	return 0;
}


