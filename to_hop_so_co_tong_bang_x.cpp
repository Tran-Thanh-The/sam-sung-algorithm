#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[25];
vector<int> v;
bool check;

void out() {
	cout << "[";
	for ( int i = 0; i < v.size(); i++) {
		cout << v[i];
		if ( i != v.size()-1)
			cout << " ";
	}
	cout << "]";
	check = false;
}

void Try( int i, int curSum) {
	for ( int j = i; j <= n; j++) {
		if ( curSum + a[j] <= x) {
			curSum += a[j];
			v.push_back(a[j]);
			
			if ( curSum == x)
				out();
			else if ( curSum < x)
				Try(j, curSum);
			curSum -= a[j];
			v.erase( v.begin() + v.size()-1);
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
		check = true;
		v.clear();
		cin >> n >> x;
		for ( int i = 1; i <= n; i++)	
			cin >> a[i];
		Try( 1, 0);
		if ( check)
			cout << -1;
		cout << endl;
	}
	return 0;
}

