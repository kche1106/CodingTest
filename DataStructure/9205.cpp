//
//  9205.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for(int t = 0; t < tc; t++) {
        int n;
        cin >> n;
        
        int home_x, home_y;
        cin >> home_x >> home_y;
        
        vector<pair<int, int>> con;
        for(int i = 0; i < n; i++) {
            int con_x, con_y;
            cin >> con_x >> con_y;
            con.push_back({con_x, con_y});
        }
        
        int rock_x, rock_y;
        cin >> rock_x >> rock_y;
        
        queue<pair<int, int>> q;
        q.push({home_x, home_y});
        int visited[100] = {0, };
        bool ans = false;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(abs(x - rock_x) + abs(y - rock_y) <= 1000) {
                ans = true;
                break;
            }
            
            for(int i = 0; i < n; i++) {
                if(visited[i] == 1) continue;
                
                if(abs(x - con[i].first) + abs(y - con[i].second) <= 1000) {
                    visited[i] = 1;
                    q.push({con[i].first, con[i].second});
                }
            }
        }
        
        if(ans) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
}
