#include <bits/stdc++.h>
using namespace std;
int n;
int a[20], x[20];
bool check[20];

void out() {
	for ( int i = 1; i <= n; i++) {
		cout << a[x[i]-1] << " ";
	}
	cout << endl;
}

void handle( int i) {
	for ( int j = 1; j <= n; j++) {
		if ( !check[j]) {
			x[i] = j;
			check[j] = true;
			if ( i == n)
				out();
			else
				handle( i+1);
			check[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

//	int test;
//	cin >> test;
//	while( test--) {
	//	memset( check, false, sizeof(check));
		cin >> n;
		for ( int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort( a, a+n);
		handle(1);
//	}
	return 0;
}

