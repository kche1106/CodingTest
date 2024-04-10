//
//  11660.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/07.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n+1, vector<int> (n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i = 1; i < n+1; i++) dp[1][i] = dp[1][i-1] + map[1][i];
    for(int i = 1; i < n+1; i++) dp[i][1] = dp[i-1][1] + map[i][1];
    for(int i = 2; i < n+1; i++) {
        for(int j = 2; j < n+1; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + map[i][j];        
        }
    }

    int x1, y1, x2, y2;
    for(int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];

        cout << ans << "\n";
    }
}