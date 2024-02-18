//
//  11057.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/06.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int dp[n+1][11];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 1) dp[i][j] = 1 % 10007;
            else if(j == 0) dp[i][j] = 1 % 10007;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
        }
    }
    
    int res = 0;
    for(int i = 0; i < 10; i++) {
        res += dp[n][i] % 10007;
    }
    
    cout << res % 10007;
}
