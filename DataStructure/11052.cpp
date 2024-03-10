//
//  11052.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/10.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int p[1001];
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    int dp[1001];
    dp[0] = 0;
    dp[1] = p[1];
    for(int i = 2; i <= n; i++) {
        
        int res = 0;
        for(int j = i/2; j <= i; j++) {
            int sum = 0;
            if(i == j) sum = p[j];
            else sum = dp[j] + dp[i-j];
            res = max(sum, res);
        }
        dp[i] = res;
    }
    
    cout << dp[n];
}
