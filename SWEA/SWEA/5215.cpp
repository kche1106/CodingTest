//
//  5215.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/11.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, l, v[21], w[21];
        int dp[21][10001];
        cin >> n >> l;
        
        for(int j = 1; j <= n; j++) {
            cin >> v[j] >> w[j];
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= l; j++) {
                if(w[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j - w[i]] + v[i], dp[i-1][j]);
            }
        }
        
        cout << "#" << i+1 << " " << dp[n][l] << endl;
    }
}
