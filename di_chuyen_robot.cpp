#include <bits/stdc++.h>
using namespace std;

int x, y;
char direc;

void direction( char a) {
	if ( direc == 'U') {
		if ( a == 'U') {
			y ++;
		}
		else if ( a == 'R') {
			x ++;
			direc = 'R';
		} 
		else if ( a == 'D') {
			y --;
			direc = 'D';
		}
		else {
			x --;
			direc = 'L';	
		}
	}
	else if ( direc == 'R') {
		if ( a == 'U') {
			x ++;
		}
		else if ( a == 'R') {
			y --;
			direc = 'D';
		} 
		else if ( a == 'D') {
			x --;
			direc = 'L';
		}
		else {
			y ++;
			direc = 'U';	
		}
	} else if ( direc == 'D') {
		if ( a == 'U') {
			y --;
		}
		else if ( a == 'R') {
			x --;
			direc = 'L';
		} 
		else if ( a == 'D') {
			y ++;
			direc = 'U';
		}
		else {
			x ++;
			direc = 'R';	
		}
	} else {
		if ( a == 'U') {
			x --;
		}
		else if ( a == 'R') {
			y ++;
			direc = 'U';
		} 
		else if ( a == 'D') {
			x ++;
			direc = 'R';
		}
		else {
			y --;
			direc = 'D';	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	x = 0, y = 0;
	direc = 'U';
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	for ( int i = 0; i < n; i++) {
		if ( s[i] == 'G')
			s[i] = 'U';
		if ( s[i] == 'B')
			s[i] = 'D';
		direction( s[i]);
	}
	
	cout << x << " " << y;
	
	return 0;
}

