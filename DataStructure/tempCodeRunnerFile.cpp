//
//  5582.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int dp[4001][4001];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[i]) dp[i][j] = 1;
        }
    }

    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}