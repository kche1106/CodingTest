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
        
        int sticker[2][100001] = {0, };
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> sticker[i][j];
            }
        }
        
        int dp[2][100001] = {0, };
        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][0] = sticker[1][0];
        dp[1][1] = sticker[0][0] + sticker[1][1];
        
        for(int j = 2; j < n; j++) {
            //(0,0)에서 시작
            dp[0][j] = sticker[0][j] + max(dp[1][j-1], dp[1][j-2]);
            //(1,0)에서 시작
            dp[1][j] = sticker[1][j] + max(dp[0][j-1], dp[0][j-2]);
        }
            
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
}
