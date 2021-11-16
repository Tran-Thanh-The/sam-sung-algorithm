#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt;
	cin >> tt;
	while( tt--) {
		int n, k = 0;
		cin >> n;
		int a[n];
		
		for ( int i = 0; i < n; i++) {
			cin >> a[i];
			k += a[i];
		}
		
		if ( k%2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		k /= 2;
		
		bool ok[k+1] = {false};
		ok[0] = true;
		for ( int i = 0; i < n; i++) {
			ok[a[i]] = true;
			for ( int j = k; j > a[i]; j--) {
				if ( ok[j-a[i]] )
					ok[j] = true;
			}
		}
		
		if ( ok[k])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

