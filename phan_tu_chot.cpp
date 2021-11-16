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
		int a[n], b[n];
		for ( int i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort( b, b+n);
		
		int max = a[0];
		int count = 0;
		for ( int i = 0; i < n; ++i) {
			if ( a[i] == b[i] && a[i] >= max && ( i == n-1 || b[i] < b[i+1]))
				++ count;
			if ( a[i] > max)
				max = a[i];
		}
		cout << count << endl;
	}
	return 0;
}

