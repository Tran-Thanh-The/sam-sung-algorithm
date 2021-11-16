#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int test;
	cin >> test;
	
	cin.ignore(1);
	
	while( test--) {
		string s, tmp;
		cin >> s;
		
		vector<string> v;
		stringstream ss(s);
		while ( ss >> tmp) {
			v.push_back(tmp);
		}
		
		int count = 0;
		for ( int i = 0; i < v.size(); i++) {
			if ( count + v[i].size() <= 0) {
				cout << v[i]; 
				cout << " ";
				count += ( 1 + v[i].size());
			}
		}
		cout << endl;
	}
	return 0;
}

