#include <bits/stdc++.h>
using namespace std;

void handle( long long a, long long b) {
	long long mau = 0;
	if ( a == 1) {
		cout << a << "/" << b;
		return;
	}

	while( true) {
		if ( b%a == 0) {
			cout << "1/" << b/a;
			return;
		}
		else {
			mau = 1 + b/a;
			cout << "1/" << mau << " + ";
			first = true;
			a = a*mau - b;
			b = b*mau;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		long long tu, mau;
		cin >> tu >> mau;
		handle( tu, mau);
		cout << endl;
	}
	return 0;
}

