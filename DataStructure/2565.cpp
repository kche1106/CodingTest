//
//  2565.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> line;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        line.push_back({a, b});
    }
    sort(line.begin(), line.end());

    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(line[i].second > line[j].second) 
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);

    cout << n - ans;
}