#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> L1, L2;

void init() {
	L1.push_back("0");
	L2.push_back("1");
}

void genNext() {
	for ( int i = 0; i < L2.size(); i++)
		L1.push_back(L2[i]);
	L2.clear();
	for ( int i = L1.size()-1; i >= 0; i--) {
		L2.push_back(L1[i]);
	}
	for ( int i = 0; i < L1.size(); i++) {
		L1[i] = "0" + L1[i];
		L2[i] = "1"	+ L2[i];
	}
}

void handle() {
	L1.clear();
	L2.clear();
	init();
	cin >> n;
	n --;
	while( n--)
		genNext();
	for ( int i = 0; i < L1.size(); i++)
		cout << L1[i] << " ";
	for ( int i = 0; i < L2.size(); i++)
		cout << L2[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while( t--) 
		handle();
	
	return 0;
}

