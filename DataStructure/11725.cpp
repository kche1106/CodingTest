//
//  11725.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/08/08.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001
int ans[MAX];  //각 인덱스의 부모 노드가 무엇인지 저장
bool visited[MAX];  //방문했는지 안했는지
vector<int> graph[MAX];  //서로 이어져있는지

void bfs(){
    queue<int> q;
    visited[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        
        for(int i = 0; i < graph[parent].size(); i++){
            int child = graph[parent][i];
            if(!visited[child]){
                ans[child] = parent;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    bfs();
    
    for(int i = 2; i <= n; i++)
        cout << ans[i] << "\n";
}
