//
//  1138.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <iostream>
using namespace std;

int memory[10];
int answer[10];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    
    
    for(int i = 0; i < n; i++) {  //memory
        int cnt = 0;
        for(int j = 0; j < n; j++) {  //answer
            if(cnt == memory[i]) {
                if(answer[j] == 0) {
                    answer[j] = i + 1;
                    break;
                }
            }
            else {
                if(answer[j] == 0) {
                    cnt++;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    
}
