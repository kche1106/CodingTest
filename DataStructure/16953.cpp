//
//  16953.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/07.
//

#include <iostream>
using namespace std;

long a, b;
int res = 987654321;

void DFS(long x, int l) {
    if(x > b) return;
    if(x == b) {
        if(l < res) res = l;
        return;
    }
    
    DFS(x * 2, ++l);
    l--;
    DFS(x * 10 + 1, ++l);
}

int main() {
    cin >> a >> b;
    
    DFS(a, 1);
    
    if(res != 987654321) cout << res << endl;
    else cout << "-1" << endl;
}
