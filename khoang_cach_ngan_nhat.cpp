#include <bits/stdc++.h>
using namespace std;

int low( vector<int> b, int & p) {
	return *lower_bound( b.begin(), b.end(), p);
}

int up( vector<int> b, int & p) {
	return *(upper_bound( b.begin(), b.end(), p)-1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n;
	
	int y1, y2;
	cin >> m >> n >> y1 >> y2;
	
	vector<int> a, b;
	int x;
	map<int, int> M;
	
	for ( int i = 0; i < m; ++i) {
		cin >> x;
		a.push_back(x);
	}
		
	a.push_back( 1e9);
	a.push_back( -1e9);
	sort( a.begin(), a.end());
	
	int k = 1e9;
	int Min = 1e9;
	
	for ( int j = 0; j < n; ++j) {	
		cin >> x;
		int k1 = low( a, x);
		int k2 = up( a, x);
		if ( k1 == k2)
			M[k1] --;
		
		if ( abs( k1) != k) {
			k1 = abs( x - k1);
			++ M[k1];
			Min = min( k1, Min);
		}
		if ( abs( k2) != k) {
			k2 = abs( x - k2);
			++ M[k2];
			Min = min( Min, k2);
		}
	}	
	cout << (Min + abs(y1-y2))<< " " << M[Min];
	
	return 0;
}

