#include <bits/stdc++.h>
using namespace std;

int solve( int n, int a, int b, int c) {
	int ok[n+1];
	ok[1] = a;
	for ( int i = 2; i <= n; i++) {
		if ( i%2 == 0) {
			ok[i] = min(ok[i/2]+c, ok[i-1]+a);
		}
		else {
			ok[i] = min(ok[1+i/2]+b+c, ok[i-1]+a);
		}
	}
	return ok[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		cout << solve( n, a, b, c) << endl;
	}
	return 0;
}

