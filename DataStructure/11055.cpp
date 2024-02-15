//
//  11055.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int n;
    cin >> n;
    
    int a[1001];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i]) ans = dp[i];
    }
    
    cout << ans;
}
