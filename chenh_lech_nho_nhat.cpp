#include <bits/stdc++.h>
using namespace std;

int x[10];
int n, k;
bool ok[10];
string a[10];
int mi = 1e9;

int toNumber( string s) {
	int res = 0;
	for ( int i = 1; i <= k; i++) {
		res = res*10 + s[x[i]-1] - '0';
	}
	return res;
}

void out() {
	vector<int> v;
	for ( int i = 0; i < n; i++)
		v.push_back( toNumber(a[i]));
	
	sort( v.begin(), v.end());
	if ( v[v.size()-1] - v[0] < mi)
		mi = v[v.size()-1] - v[0];
}

void handle( int i) {
	for ( int j = 1; j <= k; j++) {
		if ( !ok[j]) {
			x[i] = j;
			ok[j] = true;
			if ( i == k)
				out();
			else
				handle( i+1);
			ok[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	handle(1);
	
	cout << mi;
	return 0;
}

