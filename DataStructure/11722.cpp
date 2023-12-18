//
//  11722.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/18.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j <= i; j++) {
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    
    cout << *max_element(dp, dp+n) << '\n';
}
