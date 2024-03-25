//
//  15989.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/25.
//

#include <iostream>
using namespace std;

int main() {
   int t;
   cin >> t;

   while (t--) {
      int n;
      cin >> n;

      int dp[10001][4];
      dp[1][1] = 1;
      dp[1][2] = 0;
      dp[1][3] = 0;
      dp[2][1] = 1;
      dp[2][2] = 1;
      dp[2][3] = 0;
      dp[3][1] = 1;
      dp[3][2] = 1;
      dp[3][3] = 1;

      for (int i = 4; i <= n; i++) {
         dp[i][1] = dp[i - 1][1];
         dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
         dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
      }

      cout << dp[n][1] + dp[n][2] + dp[n][3]<< "\n";
   }
}
