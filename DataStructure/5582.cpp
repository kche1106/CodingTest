//
//  5582.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
using namespace std;

int dp[4001][4001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int res = 0;
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = 1;
                if(i >= 1 && j >= 1) dp[i][j] += dp[i-1][j-1];
            }
            if(res < dp[i][j]) res = dp[i][j];
        }
    }
    
    cout << res;
}
