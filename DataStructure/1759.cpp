//
//  1759.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/16.
//

#include <iostream>
using namespace std;

char alpha[16], visited[16];
int L, C;
char ans[16];
int idx;  //ans 배열에 얼마나 들어있는지
int vow;

void DFS(int l) {
    
    if(idx == L) {
        for(int i = 0; i < L; i++) {
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') vow++;
        }
        if (vow >= 1 && L - vow >= 2) {
            for(int i = 0; i < L; i++) {
                cout << ans[i];
            }
            cout << endl;
        }
        vow = 0;
    }
    
    else {
        for(int i = l; i < C; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                ans[idx++] = alpha[i];
                DFS(i);
                visited[i] = 0;
                idx--;
            }
        }
    }
}

int main() {
    cin >> L >> C;
    
    for(int i = 0; i < C; i++) {
        cin >> alpha[i];
    }
    sort(alpha, alpha + C);
    
    DFS(0);
}
