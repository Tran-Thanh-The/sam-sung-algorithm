#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m1, n;
	cin >> m1 >> n;
	int c, d;
	cin >> c >> d;
	
	int a[m1+1], b[n+1];
	map<int, int> M;
	
	for ( int i = 0; i < m1; i++)
		cin >> a[i];
	for ( int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a+m1);
	sort(b, b+n);
	a[m1] = INT_MAX, b[n] = INT_MAX;
	int m = abs(a[0]-b[0]);
	M[m] ++;
	int i = 0, j = 0;
	
	while( i < m1 || j < n) {
		if ( i == m1) {
			++ j;
			int tmp = abs(a[i-1]-b[j]);
			if ( tmp <= m) {
				m = tmp;
				M[m] ++;
			}
			continue;
		}
		if ( j == n) {
			++ i;
			int tmp = abs(a[i]-b[j-1]);
			if ( tmp <= m) {
				m = tmp;
				M[m] ++;
			}
			continue;
		}
		
		if ( a[i] < b[j]) {
			++ i;
			int tmp = abs(a[i]-b[j]);
			if ( tmp <= m) {
				m = tmp;
				M[m] ++;
			}
		}
		else if ( b[j] < a[i]) {
			++ j;
			int tmp = abs(a[i]-b[j]);
			if ( tmp <= m) {
				m = tmp;
				M[m] ++;
			}
		}
		else {
			if ( a[i+1] < b[j+1]) {
				++i;
			}
			else {
				++j;
			}
		}
	}
	
	cout << m + abs(c-d) << " " << M[m];
	return 0;
}


