//
//  1753.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/07.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9+10;

int main() {
    int V, e;
    cin >> V >> e;
    
    int k;
    cin >> k;
    
    vector<pair<int, int>> vec[200001];  //도착지, 비용
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        vec[u].push_back({v, w});
    }
    
    int d[200001];
    fill(d, d+V+1, INF);
    d[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[k], k});
    
    while(!pq.empty()) {
        int curc = pq.top().first;  //비용
        int curl = pq.top().second;  //현재 위치
        pq.pop();
        
        if(d[curl] != curc) continue;
        
        for(int i = 0; i < vec[curl].size(); i++) {
            int nexl = vec[curl][i].first;  //현재 노드에서 뻗어나갈 수 있는 노드
            int nexc = vec[curl][i].second;  //현재 노드에서 다음 노드로 뻗어가는 비용
            if(d[nexl] <= d[curl] + nexc) continue;
            
            d[nexl] = d[curl] + nexc;
            pq.push({d[nexl], nexl});
        }
    }
    
    for(int i = 1; i <= V; i++) {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}
