//
//  2579.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/16.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int score[300], dp[300];
    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];
    dp[3] = max(score[2]+score[3], score[1]+score[3]);
    for(int i = 4; i <= n; i++) {
        
        dp[i] = max(score[i] + score[i-1] + dp[i-3], score[i] + dp[i-2]);
        
    }
    
    cout << dp[n] << endl;
}
