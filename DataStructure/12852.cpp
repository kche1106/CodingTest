//
//  12852.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
using namespace std;

int dp[1000001];
int path[1000001];

int main() {
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        path[i] = i-1;
        
        if(i % 3 == 0) {
            if(dp[i] > dp[i/3] + 1) {
                dp[i] = dp[i/3] + 1;
                path[i] = i/3;
            }
        }
        if(i % 2 == 0) {
            if(dp[i] > dp[i/2] + 1) {
                dp[i] = dp[i/2] + 1;
                path[i] = i/2;
            }
        }
    }
    
    cout << dp[n] << endl;
    
    while(n > 0) {
        cout << n << " ";
        n = path[n];
    }
}
