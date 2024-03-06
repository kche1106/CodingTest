//
//  22233.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/03/05.
//

#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;

unordered_set<string> memo;

void split(string str, char delimiter) {
	istringstream iss(str);
	string buffer;

	while (getline(iss, buffer, delimiter)) {
		if (memo.find(buffer) != memo.end()) {
			memo.erase(buffer);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		memo.insert(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
        cin >> s;
		split(s, ',');

		cout << memo.size() << "\n";
	}
}
