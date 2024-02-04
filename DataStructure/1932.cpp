//
//  1932.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v[501];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int c;
            cin >> c;
            v[i].push_back(c);
        }
    }
    
    vector<int> dp[501];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i].push_back(0);
        }
    }
    
    dp[0][0] = v[0][0];
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(j == 0) dp[i][j] = dp[i-1][j] + v[i][j];
            else if(j == v[i].size()-1) dp[i][j] = dp[i-1][j-1] + v[i][j];
            else dp[i][j] = max(dp[i-1][j-1] + v[i][j], dp[i-1][j] + v[i][j]);
        }
    }
    
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < v[i].size(); j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    int res = 0;
    for(int i = 0; i < dp[n-1].size(); i++) {
        if(res < dp[n-1][i]) res = dp[n-1][i];
    }
    
    cout << res << endl;
}
