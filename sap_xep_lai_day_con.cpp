#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while( t--) {
		int n;
		cin >> n;
		int *a = new int[n], *b = new int[n];
		
		for ( int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort( b, b+n);
		int h = -1, k = -1;
		for ( int i = 0; i < n; i++)
			if ( a[i] != b[i]) {
//				cout << i+1 << " ";
				h = i+1;
				break;
			}
		for ( int i = n-1; i >= 0; i--)
			if ( a[i] != b[i]) {
				k = i+1;
//				cout << i+1 << " ";
				break;
			}
		
		if ( h == -1 || k == -1)
			cout << 0;
		else
			cout << h << " " << k;
		cout << endl;
		delete a, b;
	}
	
	return 0;
}




