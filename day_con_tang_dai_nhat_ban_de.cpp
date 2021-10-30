#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	for ( int i = 0; i < n; i++)	
		cin >> a[i];
	int ok[n];
	memset( ok, 0, sizeof(ok));
	
	int result = 0;
	for ( int i = 0; i < n; i++) {
		ok[i] = 1;
		
		for ( int j = 0; j < i; j++) {
			if ( a[i] > a[j] )
				ok[i] = max( ok[i], 1+ok[j]);
		}
		result = max( result, ok[i]);
	}
	cout << result;
	
	return 0;
}

