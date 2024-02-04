//
//  12852.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int path[1000001];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        path[i] = i-1;
        
        if(i % 3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i]);
            path[i] = (dp[i/3] + 1 > dp[i]) ? path[i] : i/3;
        }
        if(i % 2 == 0) {
            dp[i] = min(dp[i/2] + 1, dp[i]);
            path[i] = (dp[i/2] + 1 > dp[i]) ? path[i] : i/2;
        }
    }
    
    cout << dp[n] << endl;
    cout << n << " ";
    while (n > 1) {
        n = path[n];
        cout << n << " ";
    }
}
