//
//  9465.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/06.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int a[2][100001] = {0, };
        int dp[2][100001] = {0, };
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        
        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        dp[0][1] = a[0][1] + a[1][0];
        dp[1][1] = a[1][1] + a[0][0];
        
        for(int j = 2; j < n; j++) {
            dp[0][j] = a[0][j] + max(dp[1][j-1], dp[1][j-2]);
            dp[1][j] = a[1][j] + max(dp[0][j-1], dp[0][j-2]);
            
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
}
