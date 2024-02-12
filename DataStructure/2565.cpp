//
//  2565.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <algorithm>
using namespace std;

int line[501];
int dp[501];

int main() {
    int n;
    cin >> n;
    
    int size = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if(size < a) size = a;
        line[a] = b;
    }
    
    int ans = 0;
    for(int i = 1; i <= size; i++) {
//        dp[i] = 1;
        for(int j = i-1; j >= 0; j--) {
            if(line[j] < line[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    
    cout << n - ans;
}
