#include <bits/stdc++.h>
using namespace std;
long long n, k, S;
long long a[100], x[100];
bool r = false;

bool check() {
	long long sum = 0;
//	for ( int i = 1; i <= k; i++)
//		cout << x[i] << " "; cout << endl;
	for ( int i = 1; i <= k; i++) {
		sum += a[x[i]-1];
//		cout << a[x[i]] << " ";
	}
//	cout << sum << endl;
	if ( sum == S) {
		r = true;
		return true;	
	}
	return false;
}

void handle( int i) {
	if ( r)
		return;
	for ( int j = x[i-1]+1; j <= n-k+i; j++ ) {
		x[i] = j;
		if ( i == k) {
			if ( check())
				return;
		}
		else {
			handle( i+1);
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> S; 
	
	for ( int i = 0; i < n; i++)
		cin >> a[i];
		
	for ( int i = 1; i <= n; i++) {
		k = i;
		handle(1);
		if ( r) {
			cout << k;
			return 0;
		}
			
	}
	cout << -1;
	
	return 0;
}

