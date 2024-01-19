//
//  1138.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <iostream>
using namespace std;

int memory[10];
int ans[10];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    
    ans[memory[0]] = 1;  //키가 1인 사람
    
    for(int i = 1; i < n; i++) {  //memory
        int cnt = 0;
        for(int j = 0; j < n; j++) {  //answer
            if(cnt == memory[i]) {
                if(ans[j] == 0) {
                    ans[j] = i+1;
                    break;
                }
            }
            else {
                if(ans[j] == 0) cnt++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
