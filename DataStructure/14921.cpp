//
//  14921.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
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
    
    int start = 0;
    int end = n-1;
    
    int res = 2000000001;
    while (start < end) {
        int sum = a[start] + a[end];
        if(abs(sum) < abs(res)) res = sum;
        
        if(sum < 0) start += 1;
        else if(sum > 0) end -= 1;
        else break;
    }
    
    cout << res;
}
