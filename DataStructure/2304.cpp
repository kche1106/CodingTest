//
//  2304.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/03/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;

	int maxh = 0;
	int maxh_idx = 0;
	int s_idx = 1001;
	int e_idx = 0;
	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		arr[l] = h;

		if (s_idx > l) s_idx = l;
		if (e_idx < l) e_idx = l;

		if (maxh < h) {
			maxh = h;
			maxh_idx = l;
		}
	}

	int res = 0;
	int h = 0;
	for (int i = s_idx; i < maxh_idx; i++) {
		if (h < arr[i]) {
			h = arr[i];
		}
		res += h;
	}

	res += maxh;

	h = 0;
	for (int i = e_idx; i > maxh_idx; i--) {
		if (h < arr[i]) h = arr[i];
		res += h;
	}

	cout << res;
}