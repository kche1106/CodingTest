//
//  1043.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visited[51];

int main() {
    int n, m;  //사람 수, 파티 수
    cin >> n >> m;
    
    int num;
    cin >> num;  //진실을 아는 사람 수
    
    queue<int> truth;
    for(int i = 0; i < num; i++) {
        int t;  //진실을 아는 사람 번호
        cin >> t;
        truth.push(t);
        visited[t] = 1;
    }
    
    vector<int> party[51];
    vector<int> human[51];
    for(int i = 0; i < m; i++) {  //m개의 파티
        int n;  //각 파티 인원
        cin >> n;
        for(int j = 0; j < n; j++) {
            int p;
            cin >> p;
            party[i].push_back(p);
            human[p].push_back(i);
        }
    }
    
    vector<int> res;
    while(!truth.empty()) {
        int x = truth.front();
        truth.pop();
        
        for(int i = 0; i < human[x].size(); i++) {
            int id = human[x][i];
            res.push_back(id);
            for(int j = 0; j < party[id].size(); j++) {
                if(visited[party[id][j]] == 0) {
                    visited[party[id][j]] = 1;
                    truth.push(party[id][j]);
                }
            }
        }
    }
    
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    
    cout << m - res.size();
}
