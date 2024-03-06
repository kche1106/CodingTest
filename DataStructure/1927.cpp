//
//  1927.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/03/05.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x > 0) {
			q.push(x);
		}

		else if (x == 0) {
			if (q.empty()) cout << 0;
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
}