//
//  16987.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/20.
//

#include <iostream>
using namespace std;

int n;
int s[8];  //내구도
int w[8];  //무게
int res;

void DFS(int idx) {
    if(idx == n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] <= 0) sum++;
        }
        if(res < sum) res = sum;
        return;
    }
    
    if(s[idx] <= 0) DFS(idx + 1);
    
    else {
        bool check = false;  //남은 계란 X
        for(int i = 0; i < n; i++) {
            if(i == idx || s[i] <= 0) continue;
            
            s[idx] -= w[i];
            s[i] -= w[idx];
            check = true;
            DFS(idx+1);
            s[idx] += w[i];
            s[i] += w[idx];
        }
        
        if(check == false) DFS(idx + 1);  //깨트릴 계란 없으면 다음 계란으로
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }
    
    DFS(0);
    
    cout << res << endl;
}
