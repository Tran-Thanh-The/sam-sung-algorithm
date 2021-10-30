#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
vector<int> vNumber;
int a[1000], x[1000];
bool check = true;

void out() {
	string s = "";
	for ( int i = 0; i < vNumber.size(); i++) {
		s += to_string(vNumber[i]);
		if ( i != vNumber.size())
			s += " ";	
	}
	v.push_back(s);
	check = false;
}

void handle( int i) {
	for ( int j = i+1; j <= n; j++) {
		if ( vNumber.size() == 0 || a[j] >= vNumber[vNumber.size()-1]) {
			vNumber.push_back(a[j]);
			if ( vNumber.size() > 1) 
				out();
			handle( j);
			vNumber.erase(vNumber.begin() + vNumber.size()-1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for ( int i = 1; i <= n; i++)
		cin >> a[i];
	
	handle( 0);
	
	sort( v.begin(), v.end());

	for ( int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	
	if ( check)
		cout << -1;
	
	return 0;
}

