//
//  1439.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/02/29.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> a;
	vector<int> ch;
	int tmp = s[0];
	ch.push_back(0);
	for (int i = 0; i < s.length(); i++) {
		a.push_back(s[i]);
		if (s[i] != tmp) ch.push_back(i);
		tmp = s[i];
	}

	int even = 0;
	int odd = 0;
	for (int i = 0; i < ch.size(); i++) {
		if (i % 2 == 0) even++;
		else odd++;
	}

	if (even > odd) cout << odd;
	else cout << even;



}