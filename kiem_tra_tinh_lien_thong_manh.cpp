#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1005];
bool ok[1005];

void DFS(int i) {
	ok[i] = true;
	for ( auto j:ke[i]) 
		if ( !ok[j])
			DFS(j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		for ( int i = 0; i < 1005; i++)
			ke[i].clear();
		memset(ok, false, sizeof(ok));
		int N, K;
		cin >> N >> K;
		
		for ( int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			ke[u].push_back(v);
//			ke[v].push_back(u);
		}
		
		int res = 0;
		for ( int i = 1; i <= N; i++) {
			if ( !ok[i]) {
				res ++;
				DFS(i);
			}
		}
		
		if ( res == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

