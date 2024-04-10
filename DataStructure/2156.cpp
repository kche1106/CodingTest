//
//  2156.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/07.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int grape[10001];
    for(int i = 0; i < n; i++) {
        cin >> grape[i];
    }

    vector<int> dp(n, 0);
    dp[0] = grape[0];
    dp[1] = grape[0] + grape[1];
    dp[2] = max(grape[0], grape[1]) + grape[2];
    dp[2] = max(dp[2], dp[1]);

    for(int i = 3; i < n; i++) {
        dp[i] = max(dp[i-2], grape[i-1] + dp[i-3]) + grape[i]; 
        dp[i] = max(dp[i], dp[i-1]); 
    }

    cout << dp[n-1];
}