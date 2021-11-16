#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];
vector<vector<int>> v;
vector<int> vNumber;
vector<int> tmp;

bool isPrime( int n) {
	if( n < 2)
		return false;
	for ( int i = 2; i <= sqrt(n); ++i)
		if ( n%i == 0)
			return false;
	return true;
}

void out() {
	v.push_back(vNumber);
}

void Try( int total, int i) {
	for ( int j = i+1; j <= n; ++j) {
		vNumber.push_back(a[j]);
		total += a[j];
		
		if ( isPrime(total))
			out();
			
		Try( total, j);
		total -= a[j];
		vNumber.erase( vNumber.begin() + vNumber.size()-1);
	}
}

bool cmp( vector<int> a, vector<int> b) {
	int n = min( a.size(), b.size());
	for ( int i = 0; i < n; i++) {
		if ( a[i] != b[i])
			return a[i] < b[i];
	}
	return a.size() < b.size();
}

bool tt( int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		memset( a, 0, sizeof(a));
		v.clear();
		vNumber.clear();
		
		cin >> n;
		for ( int i = 1; i <= n; ++i)
			cin >> a[i];
		sort( a+1, a+n+1, tt);
		
		Try( 0, 0);
		
		sort( v.begin(), v.end(), cmp);
	
		
		for ( int i = 0; i < v.size(); ++i) {
			for ( auto j:v[i]) 
				cout << j << " ";
			cout << endl;
		}
		
	}
	return 0;
}


