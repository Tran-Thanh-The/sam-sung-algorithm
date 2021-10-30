#include <bits/stdc++.h>
using namespace std;

char c;
int n, k;
int x[30];

void out() {
	for ( int i = 1; i <= k; i++) {
		cout << (char)(64+x[i]);
	}
	cout << endl;
}

void handle( int i) {
	for ( int j = x[i-1]; j <= n; j++) {
		x[i] = j;
		if ( i == k)	
			out();
		else
			handle( i+1);
	}
}
	
int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c >> k;
	n = c - 64;
	x[0] = 1;
	handle(1);
	
	return 0;
}

