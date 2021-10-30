/*
	Name: Lam tron so
	Copyright: 
	Author: Tran The
	Date: 16/10/21 10:18
	Description: 
*/

#include <bits/stdc++.h>
using namespace std;

void handle( int number) {
	int du = 0;

	string res = "";
	while( number > 9) {
		int endNumber = number%10 + du;
		if ( endNumber >= 5)
			du = 1;
		else
			du = 0;
		res += "0";
		number /= 10;
	}
	number += du;
	res = to_string(number) + res;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int test;
	cin >> test;
	while( test--) {
		int s;
		cin >> s;
		
		handle(s);
	}
	return 0;
}

