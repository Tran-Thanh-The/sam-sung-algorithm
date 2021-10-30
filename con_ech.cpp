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
		long long a[n+1];
		a[0] = 1;
		for ( int i = 1; i <= n; ++i) {
			a[i] = 0;
			for ( int j = i-1; j >= max( 0, i-3); --j)
				a[i] += a[j];
		}
		cout << a[n] << endl;
	}
	return 0;
}

