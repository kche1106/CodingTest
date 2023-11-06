//
//  2806.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/05.
//

#include <iostream>
using namespace std;

int visited[10];  //visited[i] = j
int n, res = 0;

bool check(int cnt) {
    for(int i = 0; i < cnt; i++) {
        if(visited[cnt] == visited[i]) return 0;  //열이 같음
        if(cnt - i == abs(visited[cnt] - visited[i])) return 0;  //대각선이 같음
    }
    
    return 1;
}

void nqueen(int cnt) {
    if(cnt == n) res++;
    else {
        for(int i = 0; i < n; i++) {
            visited[cnt] = i;
            if(check(cnt)) nqueen(cnt+1);
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
        res = 0;
    }
}
