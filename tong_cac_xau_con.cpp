#include <bits/stdc++.h>
using namespace std;

int n;
long long sum;
string s;
vector<char> v;

void out() {
	long long k = 0;
	for ( auto i:v) 
		k = k*10 + i - '0';
//	cout << k << endl;
	sum += k;
}

void Try( int i) {
	if ( i == n)
		return;
	v.clear();
	for ( int j = i; j < n; j++) {
		v.push_back(s[j]);
		out();
	}
	Try( i+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		sum = 0;
		cin >> s;
		n = s.length();
		Try( 0);
		cout << sum << endl;
	}
	return 0;
}

