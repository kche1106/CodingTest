//
//  15686.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/17.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m;
int map[51][51];
int dis[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> live;
int ch[51];
int answer = 100000000;

int calculate() {
    int sum = 0;  //도시의 치킨거리
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
        
            int d = 100000;
            if(map[i][j] == 1) {  //집
                for(int k = 0; k < live.size(); k++) {
                    int distance = abs(i - live[k].first) + abs(j - live[k].second);
                    d = min(d, distance);
                }
                sum += d;
            }
        }
    }
    return sum;
}

void select(int idx, int cnt) {
    if(cnt == m) {
        answer = min(answer, calculate());
    }
    
    else {
        for(int i = idx; i < chicken.size(); i++) {
            if(ch[i] != 1) {
                ch[i] = 1;
                live.push_back(chicken[i]);
                select(i, cnt+1);
                ch[i] = 0;
                live.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    
    select(0, 0);
    
    cout << answer << endl;
}
