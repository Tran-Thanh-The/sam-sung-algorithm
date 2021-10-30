#include <bits/stdc++.h>
using namespace std;

vector<int> floo[1005];
bool check[1005];
int tr[1005];

void DFS( int f, int v) {
	if ( check[v]) 	
		return;
	check[f] = true;
	for ( int i = 0; i < floo[f].size(); ++i) {
		if ( !check[floo[f][i]]) {
			tr[floo[f][i]] = f;
			DFS( floo[f][i], v);
		}
	}
}

void trace( int u, int v) {
	if ( !check[v]) {
		cout << -1 << endl;
		return;
	}
	vector<int> a;
	while( u != v) {
		if ( v == 0) {
			cout << -1 << endl;
			return;
		}
		a.push_back(v);
		v = tr[v];
	}
	a.push_back(u);
	for ( int i = a.size()-1; i >= 0; i--)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int test;
	cin >> test;
	while( test--) {	
		for ( int i = 0; i < 1005; ++i) {
			floo[i].clear();
		}
		memset( check, false, sizeof(check));
		memset( tr, 0, sizeof(tr));
		
		int E, V, B, F;
		cin >> V >> E >> B >> F;
		
		for ( int i = 0 ; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			floo[u].push_back(v);
		//	floo[v].push_back(u);		
		}
		
		DFS( B, F);
		trace( B, F);
		
		cout << endl;
	}
	return 0;
}

