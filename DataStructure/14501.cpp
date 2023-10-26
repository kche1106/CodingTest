//
//  14501.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
using namespace std;

int t[16], p[16];
int dp[16];

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    

    for(int i = n; i > 0; i--) {
        int next = i + t[i];
        if(next > n + 1) {
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], p[i] + dp[next]);
        }
    }
    
    cout << dp[1] << endl;
}
