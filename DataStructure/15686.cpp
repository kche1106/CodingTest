//
//  15686.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> chic_select;
int ch[13];
int ans = 10000;

int distance() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 1) {
                int dist = 10000;
                for(int k = 0; k < chic_select.size(); k++) {
                    dist = min(dist, abs(i - chic_select[k].first) + abs(j - chic_select[k].second));
                }
                sum += dist;
            }
        }
    }
    return sum;
}

void select(int idx, int cnt) {
    if(cnt == m) {
        if(ans > distance()) ans = distance();
    }
    else {
        for(int i = idx; i < chicken.size(); i++) {
            if(ch[i] != 1) {
                ch[i] = 1;
                chic_select.push_back(chicken[i]);
                select(i+1, cnt+1);
                ch[i] = 0;
                chic_select.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    
    select(0, 0);
    
    cout << ans << endl;
 }
