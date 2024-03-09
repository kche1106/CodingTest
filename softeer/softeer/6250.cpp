//
//  6250.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;;
    
    priority_queue<pair<int, int>> score[3];
    int total[n];  //점수, idx
    memset(total, 0, sizeof(total));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            int s;
            cin >> s;
            score[i].push({s, j});  //점수, 인덱스
            total[j] += s;
        }
    }
    
    int rank[3][n];
    for(int i = 0; i < 3; i++) {
        int pre = -1;
        int pre_rank = 1;
        int size = 1;
        while(!score[i].empty()) {
            int s = score[i].top().first;
            int idx = score[i].top().second;
            score[i].pop();
//            cout << "s = " << s << " " << " idx = " << idx << " total = " << total[idx] << "\n";
            
            if(pre != s) {
                rank[i][idx] = size;
                pre_rank = rank[i][idx];
            }
            else if(pre == s) {
                rank[i][idx] = pre_rank;
            }
            size++;
            pre = s;
        }
    }
    
    priority_queue<pair<int, int>> total_score;
    for(int i = 0; i < n; i++) {
        total_score.push({total[i], i});
    }
    
    int total_rank[n];
    int pre = -1;
    int pre_rank = 1;
    int size = 1;
    while(!total_score.empty()) {
        int s = total_score.top().first;
        int idx = total_score.top().second;
        total_score.pop();
        
        if(pre != s) {
            total_rank[idx] = size;
            pre_rank = total_rank[idx];
        }
        else if(pre == s) {
            total_rank[idx] = pre_rank;
        }
        size++;
        pre = s;
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cout << rank[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(int i = 0; i < 3; i++) {
        cout << total_rank[i] << " ";
    }
}
