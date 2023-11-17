//
//  2817.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/12.
//

#include <iostream>
using namespace std;

int n, k;
int num[21];
int res;

void DFS(int l, int sum) {
    
    if(l >= n) {
        if(sum == k) {
            res++;
            return;
        }
        return;
    }
    
    else {
        DFS(l+1, sum);
        DFS(l+1, sum + num[l]);
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        res = 0;
        cin >> n >> k;
        
        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }
        
        DFS(0, 0);
        
        cout << "#" << i+1 << " " << res << endl;
    }
}
