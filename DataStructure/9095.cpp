//
//  9095.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int dp[11];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[n] << "\n";
    }
}
