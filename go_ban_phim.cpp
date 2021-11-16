#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	int k = 0;
	string res = "";

	for ( int i = 0; i < s.length(); i++) {
		if ( s[i] == '<') {
			k --;
			if ( k < 0)
				k = 0;
		}
		else if ( s[i] == '>') {
			k ++;
			if ( k >= res.length())
				k = res.length();
		}
		else if ( s[i] == '-'){
			if ( k > 0)
				res.erase( k-1, 1);
		}
		else {
			string tmp = "";
			tmp += s[i];
			res.insert( k, tmp);
			k ++;
		}
	}
	cout << res;
	return 0;
}

