#include <bits/stdc++.h>
using namespace std;

vector<int> List[1005];
bool ok[1005];
bool res;
int head, k;

void DFS(int i) {
	if (res)
		return;
	ok[i] = true;
	k ++;
	for ( auto j:List[i] ) {
		if ( k > 2 && j == head) {
			res = true;
			return;
		}
		if ( !ok[j])
			DFS(j);
	}
	k --;
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
		res = false;
		
		int N, E;
		cin >> N >> E;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		
		for ( int i = 1; i <= N; i++) {
			memset(ok, false, sizeof(ok));
			head = i;
			k = 0;
			DFS(i);
			if ( res)
				break;
		}
		
		if ( res) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

