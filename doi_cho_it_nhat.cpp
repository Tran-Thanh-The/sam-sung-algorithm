#include<bits/stdc++.h>
using namespace std;

int minSwaps( vector<int> arr) {
	int ans = 0;
	int n = arr.size();
	bool c[n];
	memset( c, false, n);
	
	pair<int, int> a[n];
	for ( int i = 0; i < n; ++i) {
		a[i].first = arr[i];
		a[i].second = i;
	}
	
	sort( a, a+n);
	
	for( int i = 0; i < n; i++) {
		if ( c[i] || arr[i] == a[i].first) {
			c[i] = true;
			continue;
		}
		
		int tmp = 0, j = i;
		while( !c[j]) {
			++ tmp;
			c[j] = true;
			
			j = a[j].second;
		}
		if ( tmp > 0)
			ans += ( tmp-1);
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	while( t--) {
		vector <int> a;
		int n, x;
		cin >> n;
		
		for( int i = 0; i < n; i++) {
			cin >> x;
			a.push_back(x);
		}
		
		cout << minSwaps(a) << endl;
	}
}

