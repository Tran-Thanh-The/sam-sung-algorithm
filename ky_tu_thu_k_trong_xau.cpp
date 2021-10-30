#include <bits/stdc++.h>
using namespace std;

int lenString( int n) {
	int res = 1;
	-- n;
	while( n--) {
		res = res*2 + 1; 
	}
	return res;
}

char handle( int n, int index) {
	int l = lenString(n);
	int lf = 0, r = l-1; 
	while( n--) {
		if ( index == (lf + r)/2 )
			return char(65+n);
		else if ( index > (lf + r)/2) {
			lf = 1 + (lf + r)/2;
		} else {
			r = -1 + (lf + r)/2;
		}
	}
	return 'A';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int test;
	cin >> test;
	while( test--) {
		int number, index;
		cin >> number >> index;
		cout << handle(number, index-1) << endl;
	}
	return 0;
}

