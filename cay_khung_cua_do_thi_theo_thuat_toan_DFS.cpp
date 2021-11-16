#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

vector<int> List[1005];
vector<pair<int, int>> res;
bool ok[1005];

void DFS(int u) {
	ok[u] = true;
	
	for ( auto i:List[u]) {
		if ( !ok[i]) {
			res.push_back(p(u,i));
			DFS(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		for ( int i = 0; i < 1005; i++)
			List[i].clear();
		res.clear();
		memset(ok, false, sizeof(ok));
		
		int N, E, U;
		cin >> N >> E >> U;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		
		DFS(U);
		
		if ( res.size() != N-1)
			cout << -1 << endl;
		else
			for ( auto i:res)
				cout << i.first << " " << i.second << endl;
	}
	return 0;
}

