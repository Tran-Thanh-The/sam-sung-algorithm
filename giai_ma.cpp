#include <bits/stdc++.h>
using namespace std;

int handle( string s) {
	int n = s.length();
	s = " " + s; 
	
	if ( s[1] == '0')
		return 0;
	
	int res[n+1];
	memset( res, 0, sizeof(res));
	res[1] = res[0] = 1;
	
	for ( int i = 2; i <= n; ++i) {
		if( s[i] > '0')		// 101 => "10" = true, "0" = false, "01" = false => if s[i] = '0' then s[i] can only be combined with s[i-1] 
			res[i] = res[i-1];
		if ( (s[i-1] == '1') || ( s[i-1] == '2' && s[i] <= '6'))
			res[i] += res[i-2];
	}

	return res[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		string s;
		cin >> s;
		cout << handle( s) << endl;
	}
	return 0;
}

