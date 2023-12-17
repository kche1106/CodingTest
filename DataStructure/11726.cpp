//
//  11726.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/17.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    
    cout << dp[n] << endl;
}
