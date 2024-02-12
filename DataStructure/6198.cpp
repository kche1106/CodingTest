//
//  6198.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long res = 0;
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        
        if(s.empty()) s.push(h);
        else {
            while(!s.empty() && s.top() <= h) s.pop();
            res += s.size();
            s.push(h);
        }
    }
    
    cout << res;
}
