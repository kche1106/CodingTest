//
//  2217.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/02/29.
//

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int rope[100001];
	int min = 10000;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
		if (min > rope[i]) min = rope[i];
		if (max < rope[i]) max = rope[i];
	}

	int res = 0;
	for (int i = min; i <= max; i++) {
		int weight = i * n;

		for (int j = 0; j < n; j++) {
			if (rope[j] < i) weight -= i;
		}
		if (res < weight) res = weight;
	}

	cout << res;
}