//
//  12865.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/16.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            // 못 담음
            if(w[i] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            // 담음
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    
    cout << dp[n][k] << endl;
}
