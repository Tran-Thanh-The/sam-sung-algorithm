#include <bits/stdc++.h>
using namespace std;

bool handle( long long n, string s) {
	string str = to_string(n);
	n = str.length();
	
	int x = 0;
	int dem = 0;
	for ( int i = 0; i < n; i++) {
		for ( int j = x; j < s.length(); j++) {
			if ( s[j] == str[i]) {
				x = j+1;
				dem ++;
				break;
			}
		}
	}
	if ( dem == n)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt;
	cin >> tt;
	while( tt--) {
		string s;
		cin >> s;
		long long n = s.length();
		long long Max = -1, i;
		
		for ( i = 1; i*i*i <= pow(10, n); i++)
			if ( handle(i*i*i, s))
				Max = i*i*i;
		cout << Max << endl;
	}
	return 0;
}


