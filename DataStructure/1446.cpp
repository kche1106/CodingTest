//
//  1446.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/07.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 10;

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<pair<int ,int>> vec[10001];
    for(int i = 0; i < d; i++) {
        vec[i].push_back({1, i+1});  //지름길로 안갈때
    }
    
    for(int i = 0; i < n; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        vec[s].push_back({l, e});  //거리, 도착위치
    }
    
    int dist[10001];
    fill_n(dist, 10001, INF);
    dist[0] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});  //거리 시작위치
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.second] != cur.first) continue;
        for(int i = 0; i < vec[cur.second].size(); i++) {
            auto nex = vec[cur.second][i];
            if(dist[nex.second] <= dist[cur.second] + nex.first) continue;
            
            dist[nex.second] = dist[cur.second] + nex.first;
            pq.push({dist[nex.second], nex.second});
        }
    }
    
    cout << dist[d];
}
