#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, x;
	cin >> n >> m;
	int a[m+1] = {0};
	
	for ( int i = 0; i < n; i++)  {
		cin >> x;
		a[x] ++;
	}
	int max = a[1];
	for ( int i = 1; i <= m; i++ ) 
		if ( max < a[i])
			max = a[i];
	for ( int i = 1; i <= m; i++)
		if ( max == a[i])
			a[i] = -1;
	int max2 = 0, vt = -1;
	for ( int i = 1; i <= m; i++) 
		if ( a[i] > max2) {
			max2 = a[i];
			vt = i;
		}
	if ( vt == -1)
		cout << "NONE";
	else
		cout << vt;
}
