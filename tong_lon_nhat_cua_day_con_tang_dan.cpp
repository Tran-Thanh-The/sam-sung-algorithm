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
		int ok[n];
		
		int result = -1e9;
		for ( int i = 0; i < n; i++) {
			ok[i] = a[i];
			
			for ( int j = 0; j < i; j++) {
				if ( a[i] > a[j] )
					ok[i] = max( ok[i], a[i]+ok[j]);
			}
			result = max( result, ok[i]);
		}
		cout << result << endl;
	}
	return 0;
}

