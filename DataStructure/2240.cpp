//
//  2240.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/08.
//

#include <iostream>
using namespace std;

int main() {
    int t, w;
    cin >> t >> w;
    
    int list[1001];
    for (int i = 0; i < t; i++) {
        cin >> list[i];
    }
    
    int dp[31][2][1001];
    for(int i = 0; i <= w; i++) {
        for(int j = 0; j < t; j++) {
            
            if(i == 0) {  //시작일 땐 1번 나무에
                if(list[j] == 1)
                    dp[i][0][j] = dp[i][0][j-1] + 1;
                else dp[i][0][j] = dp[i][0][j-1];
            }
            
            else {
                if(list[j] == 1) {
                    dp[i][0][j] = max(dp[i][0][j-1] + 1, dp[i-1][1][j-1] + 1);
                    dp[i][1][j] = max(dp[i][1][j-1], dp[i-1][0][j-1]);
                }
                else if(list[j] == 2) {
                    dp[i][0][j] = max(dp[i][0][j-1], dp[i-1][1][j-1]);
                    dp[i][1][j] = max(dp[i][1][j-1] + 1, dp[i-1][0][j-1] + 1);
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j <= w; j++) {
            ans = max(ans, dp[j][i][t-1]);
        }
    }
    
    cout << ans;
}
