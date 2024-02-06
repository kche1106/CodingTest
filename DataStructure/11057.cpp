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
    
    int dp[1001][10];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(i == 1 || j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
        }
    }
    
    int sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum += dp[n][i];
    }
    
    cout << sum % 10007;
}
