//
//  1912.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/06.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[100000];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int dp[100000];
    for(int i = 0; i < n; i++) {
        dp[i] = a[i];
    }
    
    for(int i = 0; i < n; i++) {
        dp[i] = max(dp[i], dp[i-1] + a[i]);
    }
    
    int res = -1001;
    for(int i = 0; i < n; i++) {
        if(res < dp[i]) res = dp[i];
    }
    
    cout << res;
}
