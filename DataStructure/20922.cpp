//
//  20922.cpp
//  DataStructure
//
//  Created by ±èÃ¤Àº on 2024/03/05.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		nums.push_back(w);
	}

	int start = 0;
	int ans = 0;
	map<int, int> cnt;
	for (int end = 0; end < n; end++) {
		cnt[nums[end]]++;
		while (cnt[nums[end]] > k) {
			cnt[nums[start]]--;
			start++;
		}
		ans = max(ans, end - start + 1);
	}

	cout << ans;
}

/*
5 1
3 3 3 1 2

8 1
3 1 2 4 3 5 6 3
*/