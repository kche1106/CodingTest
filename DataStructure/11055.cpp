//
//  11055.cpp
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
    
    int a[1001];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int dp[1001];
    for(int i = 0; i < n; i++) {
        dp[i] = a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i]) ans = dp[i];
    }
    
    cout << ans << endl;
}
