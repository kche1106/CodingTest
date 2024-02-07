//
//  2156.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/07.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10001];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int dp[10001];
    dp[0] = a[0];
    dp[1] = dp[0] + a[1];
    dp[2] = max(a[0] + a[1], a[0] + a[2]);
    dp[2] = max(dp[2], a[1] + a[2]);
    
    for(int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-1], a[i] + a[i-1] + dp[i-3]);
        dp[i] = max(dp[i], a[i] + dp[i-2]);
    }
    
    cout << dp[n-1];
}
