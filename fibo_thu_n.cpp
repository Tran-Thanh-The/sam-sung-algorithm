#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long n;
long long F[2][2];
long long M[2][2];

void multiplication( long long f[2][2], long long m[2][2]) {
	long long f00 = ( f[0][0]*m[0][0]%mod + f[0][1]*m[1][0]%mod)%mod;
	long long f01 = ( f[0][0]*m[0][1]%mod + f[0][1]*m[1][1]%mod)%mod;
	long long f10 = ( f[1][0]*m[0][0]%mod + f[1][1]*m[1][0]%mod)%mod;
	long long f11 = ( f[1][0]*m[0][1]%mod + f[1][1]*m[1][1]%mod)%mod;
	f[0][0] = f00;
	f[0][1] = f01;
	f[1][1] = f11;
	f[1][0] = f10;
}

void Pow( long long f[2][2], long long n) {
	if ( n <= 1)
		return;
	Pow( f, n/2);
	multiplication( F, F);
	if ( n%2 == 1)
		multiplication( F, M);
		
}

void solve() {
	F[0][0] = F[0][1] = F[1][0] = 1;
	F[1][1] = 0;
	M[0][0] = M[1][0] = M[0][1] = 1;
	M[1][1] = 0;
	
	if ( n == 0)
		cout << 0 << endl;
	else {
		Pow( F, n-1);
		cout << F[0][0] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int test;
	cin >> test;
	while( test--) {
		cin >> n;
		solve();
	}
	return 0;
}

