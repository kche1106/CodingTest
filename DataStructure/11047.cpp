//
//  11047.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/02/29.
//

#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int coin[11];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (k >= coin[i]) {
			res++;
			k -= coin[i];
			if (k == 0) break;
		}
	}

	cout << res;
}