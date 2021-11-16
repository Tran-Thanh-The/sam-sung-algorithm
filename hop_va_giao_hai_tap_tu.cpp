#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//  setprecision

		string s, tmp;
		map<string, bool> m;
		getline( cin, s);
		for ( int i = 0; i < s.length(); ++i) 
			if ( s[i] >= 65 && s[i] <= 90)
				s[i] += 32;
				
		stringstream ss(s);
		vector<string> a, b, res;
		while( ss >> tmp) {
			a.push_back(tmp);
		}
		getline( cin, s);
		for ( int i = 0; i < s.length(); ++i) 
			if ( s[i] >= 65 && s[i] <= 90)
				s[i] += 32;
		stringstream sss(s);
		while( sss >> tmp) {
			b.push_back(tmp);
		}
		
		for ( auto i:a) {
			if ( !m[i])
				res.push_back(i);
			m[i] = true;
		}
		for ( auto i:b) {
			if ( !m[i]) {
				res.push_back(i);
				m[i] = true;
			}
		}
		sort( res.begin(), res.end());
		for ( auto i:res)
			cout << i << " ";
		cout << endl;
		m.clear();
		res.clear();
		for ( auto i:a) {
			m[i] = true;
		}
		for ( auto i:b) {
			if ( m[i]) {
				res.push_back(i);
				m[i] = false;
			}
		}
		sort( res.begin(), res.end());
		for ( auto i:res)
			cout << i << " ";
		cout << endl;
	return 0;
}

