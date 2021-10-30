#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a[10001];
	a[1] = 1, a[2] = 2, a[3] = 3;
	for ( int i = 4; i <= 10000; ++i) {
		a[i] = i;
		for ( int j = 1; j <= sqrt(i); j++ ) {
			a[i] = min( a[i], 1+a[i-j*j]);
		}		
	}
	
	int test;
	cin >> test;
	while( test--) {
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}

