//
//  15486.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/09.
//

#include <iostream>
using namespace std;

int dp[1500001];

int main() {
    int n;
    cin >> n;
    
    int t[1500001];
    int p[1500001];
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    
    for(int i = n; i >= 1; i--) {
        if(i + t[i] > n+1) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], p[i] + dp[i + t[i]]);
    }
    
    cout << dp[1];
}
