#include <bits/stdc++.h>
using namespace std;
bool check;
void out( vector<char> v) {
	for ( auto i:v)
		cout << i;
	cout << " ";
	check = false;
}

void Try( int a[10][10], bool b[10][10], vector<char> v, int n, int i, int j) {
	b[i][j] = false;
	if ( i == n && j == n) {
		out( v);
		b[i][j] = true;
		return;
	}
	
	if ( i != n && b[i+1][j] && a[i+1][j] == 1) {
		v.push_back('D');
		Try( a, b, v, n, i+1, j);
		v.erase( v.begin() + v.size()-1);
	}
	
	if ( j != 1 && b[i][j-1] && a[i][j-1] == 1) {
		v.push_back('L');
		Try( a, b, v, n, i, j-1);
		v.erase( v.begin() + v.size()-1);
	}

	if ( j != n && b[i][j+1] && a[i][j+1] == 1) {
		v.push_back('R');
		Try( a, b, v, n, i, j+1);
		v.erase( v.begin() + v.size()-1);
	}

	if ( i != 1 && b[i-1][j] && a[i-1][j] == 1) {
		v.push_back('U');
		Try( a, b, v, n, i-1, j);
		v.erase( v.begin() + v.size()-1);
	}

	b[i][j] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int a[10][10];
		bool b[10][10];
		vector<char> v;
		check = true;
		memset( b, true, sizeof(b));
		int n;
		cin >> n;
		for ( int i = 1; i <= n ; i++) 
			for ( int j = 1; j <= n; j++)
				cin >> a[i][j];
		if ( a[1][1] == 0) {
			cout << -1 << endl;
			continue;
		}
		Try( a, b, v, n, 1, 1);
		if ( check)
			cout << -1;
		cout << endl;
	}
	return 0;
}

