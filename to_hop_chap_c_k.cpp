#include <bits/stdc++.h>
using namespace std;
int C[1005][1005] = {0};
int mod = 1e9+7;

void initC() {
	for ( int i = 0; i < 1005; i++)
		C[i][0] = 1;
	for ( int i = 1; i < 1005; i++) {
		for ( int j = 1; j <= i; j++)
			C[i][j] = (C[i-1][j]%mod + C[i-1][j-1]%mod)%mod;
	}
}

int main() {
	initC();
	int test;
	cin >> test;
	while( test--) {
		int n, k;
		cin >> n >> k;
		cout << C[n][k] << endl;
	}
	return 0;
}


