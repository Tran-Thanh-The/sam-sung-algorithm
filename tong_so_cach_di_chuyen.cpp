#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n, k;
		cin >> n >> k;
		int a[n+1];
		a[0] = 1;
		
		for ( int i = 1; i <= n; i++) {
			a[i] = 0;
			for ( int j = i-1; j >= max( 0, i-k); j--) {
			
				a[i] = (a[i] + a[j])%mod;
			}
		}
		cout << a[n] << endl;
	}
	return 0;
}

