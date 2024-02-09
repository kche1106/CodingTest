//
//  15486.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p;
    vector<int> t;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t.push_back(a);
        p.push_back(b);
    }
    
    vector<int> dp; //전역변수로 쓰면 에러남
    for(int i = 0; i <= n; i++) {
        dp.push_back(0);
    }
    
    for(int i = n-1; i >= 0; i--) {
        int next = i + t[i];
        if(next > n) dp[i] = dp[i+1];
        else {
            dp[i] = max(dp[i+1], dp[next] + p[i]);
        }
    }
    
    cout << dp[0];
}
