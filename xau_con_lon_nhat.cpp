#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	vector<char> v;
	v.push_back( s[s.length()-1]);
	for ( int i = s.length()-2; i >= 0; --i) {
		if ( s[i] >= v[v.size()-1])
			v.push_back(s[i]);
	}
	reverse( v.begin(), v.end());
	for ( auto i:v)
		cout << i;
	return 0;
}

