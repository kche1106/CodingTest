//
//  5014.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <queue>
using namespace std;

int ch[1000000];
int dist[1000000];

int main() {
    int f, s, g, u, d;  //층의 개수, 현 위치, 도착 위치, 위로 u층, 아래로 d층
    cin >> f >> s >> g >> u >> d;
    
    queue<int> q;
    q.push(s);
    ch[s] = 1;
    
    int ans = -1;
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        
        if(pos == g) {
            ans = dist[pos];
            break;
        }
        
        for(int i = 0; i < 2; i++) {
            int npos = pos;
            if(i == 0) npos += u;
            else if(i == 1) npos -= d;
            
            if(npos <= 0 || npos > f) continue;
            if(ch[npos] == 0) {
                ch[npos] = 1;
                q.push(npos);
                dist[npos] = dist[pos] + 1;
            }
        }
    }
    
    if(ans == -1) cout << "use the stairs" << endl;
    else cout << ans << endl;
}
