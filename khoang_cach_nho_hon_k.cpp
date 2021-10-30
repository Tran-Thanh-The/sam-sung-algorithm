#include <iostream>
#include <algorithm>
using namespace std;

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
		a[n] = 1e9;
		for ( int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort( a, a+n);
		
		long long res = 0;
		int j = 0;
		for ( int i = 0; i < n; ++i) {
			while( a[j] - a[i] < k)
				++ j; 
			res += (j-i-1);
		}
		cout << res << endl;
	}
	return 0;
}

