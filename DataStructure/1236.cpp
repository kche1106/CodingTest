//
//  1236.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/03.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    char map[51][51];
    set<int> h;
    set<int> w;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'X') {
                h.insert(i);
                w.insert(j);
            }
        }
    }
    
    int hc = n - h.size();
    int wc = m - w.size();
    
    cout << max(hc, wc);
}
