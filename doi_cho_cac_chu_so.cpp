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
		string s;
		cin >> n >> s;
		
		char tmp[100];
		for ( int i = 0; i < s.length(); i++)
			tmp[i] = s[i];
		for ( int i = 0; i < s.length(); i++) {
			for ( int j = i+1; j < s.length(); j++) {
				if ( tmp[i] < tmp[j]) {
					char c = tmp[i];
					tmp[i] = tmp[j];
					tmp[j] = c;
				}
			}
		}
		
		int i = 0;
		while( n --) {
			if( i != s.length()) {
				while( s[i] == tmp[i]) i++;
				if ( i < s.length() ) {
					int j = i;
					for ( int k = i+1; k < s.length(); k++)
						if ( s[k] == tmp[i]) 
							j = k;
					char c = s[i];
					s[i] = s[j];
					s[j] = c;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}

