//
//  7662.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/26.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        priority_queue<int, vector<int>, greater<int>> mini;  //오름차순
        priority_queue<int> maxi;  //내림차순
        map<int, int> m;
        
        int k;
        cin >> k;
        
        for(int i = 0; i < k; i++) {
            char cmd;
            cin >> cmd;
            int n;
            cin >> n;
            
            if(cmd == 'I') {
                mini.push(n);
                maxi.push(n);
                m[n]++;
            }
            if(cmd == 'D') {
                if(n == -1) {  //최솟값 삭제
                    while (!mini.empty() && m[mini.top()] == 0) {
                        mini.pop();
                    }
                    if(mini.empty()) continue;
                    m[mini.top()]--;
                    mini.pop();
                }
                else {
                    while (!maxi.empty() && m[maxi.top()] == 0) {
                        maxi.pop();
                    }
                    if(maxi.empty()) continue;
                    m[maxi.top()]--;
                    maxi.pop();
                }
            }
        }
        
        while (!maxi.empty() && m[maxi.top()] == 0) maxi.pop();
        while (!mini.empty() && m[mini.top()] == 0) mini.pop();
        
        if(mini.empty() || maxi.empty()) cout << "EMPTY\n";
        else cout << maxi.top()<< " " << mini.top() << "\n";
    }
}

