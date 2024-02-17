//
//  2302.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/06.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> vip;
    for(int i = 0; i < m; i++) {
        int v;
        cin >> v;
        vip.push_back(v);
    }
    
    int dp[41];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    int start = 1;
    int end = 0;
    int res = 1;
    for(int i = 0; i < vip.size()+1; i++) {
        if(i == vip.size()) end = n+1;
        else end = vip[i];
        
        res *= dp[end-start];
        start = end + 1;
    }
    cout << res;
}
