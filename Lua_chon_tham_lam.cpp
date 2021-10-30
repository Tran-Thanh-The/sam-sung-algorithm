
#include <bits/stdc++.h>
using namespace std;

void handle( int k, int sum) {
	if ( k == 0 || sum == 0 || 9*k < sum) {
		cout << "-1 -1" << endl;
		return;
	}
	int sum1 = sum-1, i = 1;
	string res = "";
	while( i != k) {
		if ( sum1 > 9) {
			res += "9";
			sum1 -= 9;
		} else if ( sum1 > 0) {
			res = to_string(sum1) + res;
			sum1 = 0;
		} else {
			res = "0" + res;
		}
		++ i;
	}
	res = to_string( 1 + sum1) + res;
	cout << res;
	res = "";
	i = 0;
	sum1 = sum;
	while( i != k) {
		if ( sum1 > 9) {
			res += "9";
			sum1 -= 9;
		} else if ( sum1 > 0) {
			res += to_string(sum1);
			sum1 = 0;
		} else {
			res += "0";
		}
		++ i;
	}
	cout << " " << res << endl;
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

//	int test;
//	cin >> test;
//	while( test--) {
		int lenNumber, sumNumber;
		cin >> lenNumber >> sumNumber;
		
		handle( lenNumber, sumNumber);
//	}
	return 0;
}

