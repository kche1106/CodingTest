//
//  1463.cpp
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
    
    int dp[1000000];
    dp[0] = 0;
    dp[1] = 0;
    
    for(int i = 2; i <= n; i++) {
        //1빼고 시작
        dp[i] = dp[i-1] + 1;
        //3의 배수인데 2의 배수는 아님
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        //2의 배수
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    cout << dp[n] << endl;
}
