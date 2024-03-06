//
//  3758.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(const pair<pair<int, int>, pair<int, int>> &t1, const pair<pair<int, int>, pair<int, int>> &t2) { //점수, 제출 횟수, 시간
    if(t1.first.second == t2.first.second) {
        if(t1.second.first == t2.second.first) {
            return t1.second.second < t2.second.second;
        }
        else return t1.second.first < t2.second.first;
    }
    else return t1.first.second > t2.first.second;
}

int main() {
   int T;
   cin >> T;
   
   while (T--) {
       int n, k, t, m;  //팀 수, 문제 수, 내 팀 id, 로그 엔트리
       cin >> n >> k >> t >> m;

       int solve[101][101];
       int cnt[101];
       int time[101];
       memset(solve, 0, sizeof(solve));
       memset(cnt, 0, sizeof(cnt));
       memset(time, 0, sizeof(time));
       
       for (int p = 0; p < m; p++) {
          int i, j, s;  //팀, 번호, 점수
          cin >> i >> j >> s;
          if(solve[i][j] < s) solve[i][j] = s;
          cnt[i]++;
          time[i] = p;
       }
       
      vector<pair<pair<int, int>, pair<int, int>>> score;
      for (int a = 1; a <= n; a++) {
          int sc = 0;
          for (int b = 1; b <= k; b++) sc += solve[a][b];
          score.push_back({{a, sc}, {cnt[a], time[a]}});
      }
       
       sort(score.begin(), score.end(), cmp);
       
       for(int i = 0; i < n; i++) {
           if(t == score[i].first.first) {
               cout << i+1 << "\n";
           }
       }
   }
}
