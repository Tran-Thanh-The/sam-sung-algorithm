#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long permutation[1005][1005];

void initPermutation() {
	memset( permutation, 0 , sizeof(permutation));
	
	for ( int i = 0; i < 1005; i++) 
		permutation[i][0] = 1;
	
	for ( int i = 0; i < 1005; i++) {
		for ( int j = 1; j <= i; j++) {
			permutation[i][j] = ((permutation[i][j-1]%mod) * ((i-j+1)%mod))%mod;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initPermutation();

	int test;
	cin >> test;
	while( test--) {
		int n, k;
		cin >> n >> k;
		cout << permutation[n][k] << endl;
	}
	return 0;
}

