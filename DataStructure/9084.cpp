//
//  9084.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/10.
//

#include <iostream>
#include <cstring>
using namespace std;

int dp[10001];

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int coin[21];
        for(int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        
        int money;
        cin >> money;
        
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = coin[i]; j <= money; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        
        cout << dp[money] << "\n";
    }
}
