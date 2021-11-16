#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n;
		cin >> n;
		int arr[n];
		for ( int i = 0; i < n; ++i)
			cin >> arr[i];
		
		int totalIncrease[n];
		int totalReduction[n];
		
		for ( int i = 0; i < n; ++i) {
			totalIncrease[i] = arr[i];
			for ( int j = 0; j < i; ++j) {
				if ( arr[i] > arr[j])
					totalIncrease[i] = max( totalIncrease[i], arr[i]+totalIncrease[j]);
			}
		} 
		
		for ( int i = n-1; i >= 0; --i) {
			totalReduction[i] = arr[i];
			for ( int j = i+1; j < n; ++j) {
				if ( arr[i] > arr[j])
					totalReduction[i] = max( totalReduction[i], arr[i] + totalReduction[j]);
			}
		}
		
		int res = 0;
		for ( int i = 0; i < n; ++i) {
			int sum = 0;
			for ( int j = i+1; j < n; ++j) {
				if ( arr[i] > arr[j])
					sum = max( sum, totalReduction[j]);
			}
			sum += totalIncrease[i];
			res = max( res, sum);
		}
		
		cout << res << endl;
	}
	return 0;
}

