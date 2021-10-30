#include <bits/stdc++.h>
using namespace std;

long long ok[93];

char fibo( long long m, long long n) {
	if ( m == 1)
		return 'A';
	if ( m == 2)
		return 'B';
	if ( n <= ok[m-2] ) 
		return fibo( m-2, n); 
	else
		return fibo( m-1, n-ok[m-2]);		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ok[0] = 0, ok[1] = 1;
	for ( int i = 2; i <= 92; ++i)
		ok[i] = ok[i-1] + ok[i-2];
		
	int test;
	cin >> test;
	while( test--) {
		long long m, n;
		cin >> m >> n;
		cout << fibo( m, n) << endl;
	}
	return 0;
}

