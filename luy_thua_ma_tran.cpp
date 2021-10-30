#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long F[10][10], M[10][10];
int n;

void mul( long long f[10][10], long long m[10][10]) {
	long long tmp[10][10];
	for ( int i = 0; i < n; i++) {
		for ( int j = 0; j < n; j++) {
			long long sum = 0;
			for ( int z = 0; z < n; z++)
				sum = (sum%mod + (f[i][z]*m[z][j])%mod)%mod;
			tmp[i][j] = sum;
		}
	} 
	for ( int i = 0; i < n; i++)
		for ( int j = 0; j < n; j++)
			f[i][j] = tmp[i][j];
}

void pow( long long f[10][10], long long k) {
	if ( k == 1) {
		return;
	}
	pow( f, k/2);
	mul( f, f);
	if ( k%2 == 1)
		mul( f, M);
}

void solve() {
	int k;
	cin >> n >> k;
	for ( int i = 0; i < n; i++)
		for ( int j = 0; j < n; j++) {
			cin >> F[i][j];
			M[i][j] = F[i][j];
		}
	pow( F, k);
	long long sum = 0;
	for ( int i = 0; i < n; i++)
		sum = ( F[i][n-1]%mod + sum%mod)%mod;
	cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		solve();
	}
	return 0;
}

