//
//  2512.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/14.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int r[10001];
    int start = 0;
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    int m;
    cin >> m;
    int end = m;
    
    int res_mid = 0;
    int res_gap = 1000000000;
    while(start <= end) {
        
        int mid = (start + end) / 2;
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += min(r[i], mid);
        }
        
        int gap = abs(sum - m);  //가장 적게 차이나는 것이 답
        if(sum <= m) {  //최종 예산보단 적어야함
            if(res_gap > gap) {
                res_gap = gap;
                res_mid = mid;
            }
        }
                
        if(sum < m) start = mid+1;
        else end = mid-1;
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        int a = min(res_mid, r[i]);
        if(a > res) res = a;
    }
    
    cout << res;
}
