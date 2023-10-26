//
//  9095.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
using namespace std;

int main() {
    int t, n;
    int dp[11];
    
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n;
        
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for(int j = 4; j <= n; j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        
        cout << dp[n] << endl;
    }
}
