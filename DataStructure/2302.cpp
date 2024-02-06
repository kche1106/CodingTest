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
        
    int start;
    int end;
    
    int res = 1;
    for(int i = 0; i <= m; i++) {
        if(i == 0) start = 1;
        else start = vip[i-1] + 1;
        
        if(i == m) end = n;
        else end = vip[i] - 1;
                
        int cnt = 0;
        for(int j = start; j <= end; j++) cnt++;
        
        res = res * dp[cnt];
    }
    
    cout << res;
}
