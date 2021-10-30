#include <bits/stdc++.h>
using namespace std;

long long a, b;
vector<long long> v;
long long k = 0;
long long b1;

void Try() {
	if ( k > b1)
		return;
	k = k*10 + 4;
	v.push_back(k);
	Try();
	k /= 10;
	
	k = k*10 + 7;
	v.push_back(k);
	Try();
	k /= 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	if ( a > b ) {
		int t = a;
		a = b;
		b = t;
	}
	long long g = 1e9;
	b1 = min( g, b*10);
	Try();
	sort( v.begin(), v.end());
	
	int h1 = *lower_bound( v.begin(), v.end(), a);
	int h2 = *lower_bound( v.begin(), v.end(), b);
	
	if ( h1 == h2) {
		cout << (b-a+1)*h1;
		return 0;
	}
	
	for ( int i = 0; i < v.size(); ++i) {
		if ( v[i] == h1)
			h1 = i;
		if ( v[i] == h2)
			h2 = i;
	}
	
	
	long long sum = 0;
	sum += (v[h1]-a+1)*v[h1];
	if ( h2 > h1)
		sum += (b-v[h2-1])*v[h2];
	
	for ( int i = h1+1; i < h2; ++i) {
		sum += (v[i]-v[i-1])*v[i];
	}
	 
	cout << sum;
	return 0;
}

