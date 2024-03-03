//
//  9017.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        map<int, vector<int>> m;  //팀, 등수(선수 번호)
        for(int i = 1; i <= n; i++) {
            int team;
            cin >> team;
            m[team].push_back(i);
        }
        
        int score[1001];
        for(int i = 1; i <= n; i++) score[i] = i;
        
        for(auto i = m.begin(); i != m.end(); i++) {
            if(m[i -> first].size() < 6) {
                for(int j = 0; j < m[i -> first].size(); j++) {
                    int del = m[i -> first][j];
                    score[del] = -1;
                    for(int s = del; s <= n; s++) {
                        score[s]--;
                    }
                }
            }
        }
        
//        for(int i = 1; i <= n; i++) {
//            cout << score[i] << " ";
//        }
        
        for(auto i = m.begin(); i != m.end(); i++) {
            sort(m[i -> first].begin(), m[i -> first].end());
        }
        
        int mini = 100000000;
        int min_team = 0;
        for(auto i = m.begin(); i != m.end(); i++) {
            if(m[i -> first].size() < 6) continue;
            
            int sum = 0;
            for(int j = 0; j < 4; j++) {
                sum += score[m[i->first][j]];
            }
            
            if(mini > sum) {
                mini = sum;
                min_team = i -> first;
            }
            else if(mini == sum) {
                if(score[m[min_team][4]] > score[m[i->first][4]]) {
                    min_team = i -> first;
                }
            }
        }
        
        cout << min_team << "\n";
    }
}
