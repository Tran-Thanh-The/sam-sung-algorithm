#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	long long x, sum = 0;
	for ( int i = 0; i < n; i++) {
		cin >> x;
		if ( x > 0)
			sum += 2*x;
	}
	cout << sum;
	return 0;
}

