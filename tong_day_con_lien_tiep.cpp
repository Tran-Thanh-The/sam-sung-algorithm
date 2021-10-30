#include <bits/stdc++.h>
using namespace std;

bool binary( long long k, long long a[], int n) {
	int l = 0, r = n-1;
	while( l <= r) {
		int mid = (l+r)/2;
		if ( a[mid] == k)
			return true;
		if ( a[mid] < k) 
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}

bool check( long long k, long long a[], int n) {
	if ( a[n-1]%k != 0)
		return false;
	long long k1 = a[n-1]/k;
	
	for ( long long i = 2; i < k1; i++) {
		if ( !binary( k*i, a, n))
			return false;
	}
	return true;	
}

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
		long long sum[n];
		cin >> a[0];
		sum[0] = a[0];
		for ( int i = 1; i < n; i++) {
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}
		
		for ( int i = 0; i < n; i++) {
			if ( check(sum[i], sum, n)) {
				cout << sum[i] << endl;
				break;
			}
		}
	}
	return 0;
}

