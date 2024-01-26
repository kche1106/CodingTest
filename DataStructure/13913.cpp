//
//  13913.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <queue>
using namespace std;

int n, k;
int ch[1000000];
int dist[1000000];
int path[1000000];
queue<int> q;
int res;
int cnt;

void BFS() {
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        
        if(pos == k) {
            res = dist[pos];
            break;
        }
        
        int npos = 0;
        for(int i = 0; i < 3; i++) {
            if(i == 0) npos = pos - 1;
            else if(i == 1) npos = pos + 1;
            else if(i == 2) npos = pos * 2;
            
            if(npos < 0 || npos > 100000) continue;
            if(ch[npos] == 0) {
                ch[npos] = 1;
                dist[npos] = dist[pos] + 1;
                q.push(npos);
                path[npos] = pos;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    
    q.push(n);
    ch[n] = 1;
    
    BFS();
    cout << res << endl;
    
    vector<int> ans;
    ans.push_back(k);
    
    for(int i = 0; i < res; i++) {
        ans.push_back(path[k]);
        k = path[k];
    }
    
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    
}
