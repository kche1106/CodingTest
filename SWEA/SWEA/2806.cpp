//
//  2806.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/05.
//

#include <iostream>
using namespace std;

int col[10];
int n, res = 0;

bool check(int t) {
    for(int i = 0; i < n; i++) {
        if(col[i] )
    }
}

void nqueen(int x) {
    if(x == n) res++;
    else {
        for(int i = 0; i < n; i++) {
            col[x] = i;
            if(check(x)) nqueen(x+1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n;
        
        nqueen(0);
        
        cout << "#" << i+1 << " " << res << endl;
    }
}
