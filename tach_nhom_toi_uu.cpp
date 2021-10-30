#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

//	int test;
//	cin >> test;
//	while( test--) {
		int n, k;
		cin >> n >> k;
		int a[n+1];
		for ( int i = 0; i < n; ++i)
			cin >> a[i];
		sort( a, a+n);
		a[n] = INT_MAX;
		int res = 0;
		for ( int i = 1; i <= n; ++i) {
			if ( a[i]-a[i-1] > k)
				++ res;	
		}

		cout << res;
//	}
	return 0;
}

