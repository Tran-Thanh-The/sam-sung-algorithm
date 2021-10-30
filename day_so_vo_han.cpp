#include <bits/stdc++.h>
using namespace std;

int handle( long long n, long long k) {
	long long l = 0, r = pow(2, n) - 2;
	n ++;
	while( n -- ) {
		long long mid = (l+r)/2;
		if ( mid == k-1)
			return n;
		if ( mid < k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {	
		long long n, k;
		cin >> n >> k;
		cout << handle( n, k) << endl;
	}
	return 0;
}



