#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int test;
	cin >> test;
	while( test--) {
		int n, m;
		cin >> n >> m;
		int a[n];
		for ( int i = 0; i < n; i++) {
			cin >> a[i];	
		}
		
		sort( a, a+n);
		
		int min = m;
		int res;
		for ( int i = 0; i < n-2; i++) {
			for ( int j = i+1; j < n-1; j++ ) {
				if ( a[i] + a[j] + a[j+1] <= m ) {
					int z = j+1;
					int k = a[i] + a[j];
					while( z < n && k + a[z] <= m) {
						z ++;
					}
					
//					cout << a[i] << " " << a[j] << " " << a[z-1] << " " << k + a[z-1] << endl;
//					cout << min << endl;
					if ( m- k-a[z-1] < min) {
						min = m- k-a[z-1];
						res = k + a[z-1];
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

