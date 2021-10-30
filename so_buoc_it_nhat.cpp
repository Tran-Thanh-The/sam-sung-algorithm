#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n;
		cin >> n;
		int a[n];
		for ( int i = 0; i < n; i++)	
			cin >> a[i];
		int b[n] = {0};
		int res = 0;
		for ( int i = 0; i < n; i++) {
			b[i] = 1;
			for ( int j = 0; j < i; j++) {
				if ( a[i] >= a[j])
					b[i] = max(b[i], b[j] + 1);
			}
			res = max( res, b[i]);
		}
		cout << n - res << endl;
	}
	return 0;
}

