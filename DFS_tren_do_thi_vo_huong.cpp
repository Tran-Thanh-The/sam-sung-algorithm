#include <bits/stdc++.h>
using namespace std;

vector<int> floo[1005];
bool check[1005];

void DFS( int f) {
	cout << f << " ";
	check[f] = true;
	for ( int i = 0; i < floo[f].size(); ++i) {
		if ( !check[floo[f][i]]) 
			DFS( floo[f][i]);
	}
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
		
		int E, V, U;
		cin >> V >> E >> U;
		
		for ( int i = 0 ; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			floo[u].push_back(v);
			floo[v].push_back(u);		
		}
		
		DFS( U);
		cout << endl;
	}
	return 0;
}

