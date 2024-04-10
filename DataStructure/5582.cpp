//
//  5582.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length(), vector<int>(s2.length()));

    int ans = 0;
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                if(i >= 1 && j >= 1) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }

    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans;
}