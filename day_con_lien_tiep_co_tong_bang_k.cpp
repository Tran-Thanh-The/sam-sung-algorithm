#include <bits/stdc++.h>
using namespace std;

bool brinary( long long b[], long long k, int n) {
	int l = 0, r = n-1;
	while ( l <= r) {
		int mid = (l + r)/2;
		if ( b[mid] == k)
			return true;
		if ( b[mid] < k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}

bool check( int a[], long long k, int n) {
	long long total[n];
	total[0] = a[0];
	for ( int i = 1; i < n; i++)
		total[i] = total[i-1] + a[i];
	
	for ( int i = 0; i < n; i++) {
		if ( brinary( total, k+total[i]-a[i], n))
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n;
		long long k;
		cin >> n >> k;
		int a[n];
		
		for ( int i = 0; i < n; i++) 
			cin >> a[i];	
		
		if ( k == 0) {
			bool check = true;
			for ( int i = 0; i < n; i++)
				if ( a[i] == 0) {
					cout << "YES" << endl;
					i = n;
					check = false;
				}
			if ( check)
				cout << "NO" << endl;
			continue;
		}
		
		if ( check( a, k, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}

