//
//  11659.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
using namespace std;

int a[100001];
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }
    
    while(m--) {
        int i, j;
        cin >> i >> j;
        
        cout << dp[j] - dp[i-1] << '\n';
    }
}
