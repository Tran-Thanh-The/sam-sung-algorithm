#include <bits/stdc++.h>
using namespace std;


int n, k;
int x[30];
vector<int> v1;
vector<string> v2;
bool check[1000];

void out() {
	int sum = 0;
	for ( int i = 1; i <= n; i++)
		sum = sum*10 + x[i];
	v1.push_back(sum);
}

void _out() {
	string sum = "";
	for ( int i = 1; i <= n; i++)
		sum += (char)(64 + x[i]);
	v2.push_back(sum);
}

void handle( int i) {
	for ( int j = 1; j <= n; j++) {
		x[i] = j;
		if ( i == n)	
			out();
		else
			handle( i+1);
	}
}

void _handle( int i) {
	for ( int j = 1; j <= n; j++) {
		if ( !check[j]) {
			x[i] = j;
			check[j] = true;
			if ( i == n)	
				_out();
			else 
				_handle( i+1);
			check[j] = false;	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n; 
	x[0] = 1;
	handle(1);
	memset( x, 0, sizeof(x));
	_handle(1);
	for ( int i = 0; i < v2.size(); i++) {
		for ( int j = 0; j < v1.size(); j++)
			cout << v2[i] << v1[j] << endl;
	}
		
	
	 
	return 0;
}

