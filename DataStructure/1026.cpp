//
//  1026.cpp
//  DataStructure
//
//  Created by ��ä�� on 2024/02/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());

	vector<int> b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(b.begin(), b.end(), greater<int>());

	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		res += a[i] * b[i];
	}

	cout << res;
}