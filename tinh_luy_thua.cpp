#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long pow( long long a, long long b) {
	if ( b == 0)	
		return 1;
	if ( b == 1)
		return a;
	long long t = pow( a, b/2);
	t = ( t%mod * t%mod) %mod;
	if ( b&1) 
		t = t*a%mod;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a, b;
	while( cin >> a >> b) {
		if ( a == 0 && b == 0)
			return 0;
		cout << pow( a, b) << endl;
	}
	return 0;
}

