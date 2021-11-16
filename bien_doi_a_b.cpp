#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	
	int dp[s.length()+1];
	int dpx[s.length()+1];
	
	if ( s[0] == 'A') {
		dp[0] = 0;
		dpx[0] = 1;
	}
	else {
		dp[0] = 1;
		dpx[0] = 0;
	}
	int x;
	for ( int i = 1; i < s.length(); i++) {
		x = min(dp[i-1]+1, dpx[i-1]+1);
		if ( s[i] == 'A') {
			dp[i] = dp[i-1];
			dpx[i] = x;
		}
		else {
			dpx[i] = dpx[i-1];
			dp[i] = x;
		}
	}
	
	cout << dp[s.length()-1];
	
	return 0;
}

