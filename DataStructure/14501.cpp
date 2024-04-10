//
//  14501.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t[16];
    int p[16];
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    vector<int> dp(n+2);
    if(n + t[n] > n+1) dp[n] = 0;
    else dp[n] = p[n];

    for(int i = n-1; i >= 1; i--) {
        if(i + t[i] > n+1) dp[i] = dp[i+1];
        else {
            dp[i] = max(p[i] + dp[i+t[i]], dp[i+1]);
        }
    }

    cout << dp[1];
}