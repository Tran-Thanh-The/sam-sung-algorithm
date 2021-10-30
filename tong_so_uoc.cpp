#include <bits/stdc++.h>
using namespace std;

bool handle( int n) {
	int sum = 1;
	int k = sqrt(n);
	for ( int i = 2; i <= k; ++i) {
		if ( n%i == 0) {
			sum += i;
			sum += n/i;
		}
	}
	
	if ( k*k == n)
		sum -= k;
	if ( sum >  n)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, count = 0;
	cin >> a >> b;
	if ( a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if ( a%2 == 1)
		a ++;
	for ( int i = a; i <= b; i += 2) {
		if ( handle( i)) {
			++ count;
		}
	}
	cout << count;
	
	return 0;
}

