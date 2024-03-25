//
//  16918.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/25.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Bomb {
   int t;
   int x;
   int y;

   Bomb(int t, int x, int y) {
      this->t = t;
      this->x = x;
      this->y = y;
   }
};

int main() {
   int r, c, n;  //세로, 가로, n초
   cin >> r >> c >> n;

   char map[201][201];
   queue<Bomb> bombq;
    int tmap[201][201];
    for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
           tmap[i][j] = -1;
       }
    }
    
   for (int i = 0; i < r; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < c; j++) {
         map[i][j] = s[j];
          if (s[j] == 'O') {
              bombq.push(Bomb(0, i, j));
              tmap[i][j] = 0;
          }
      }
   }
    
   int time = 2;
   int cnt = 0;
   while (time <= n) {

      if (cnt == 0) {
         for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
               if (map[i][j] == '.') {
                  map[i][j] = 'O';
                   bombq.push(Bomb(time, i, j));
                   tmap[i][j] = time;
               }
            }
         }

         cnt = 1;
      }

      else if (cnt == 1) {
          for(int i = 0; i < r; i++) {
              for(int j = 0; j < c; j++) {
                  if (tmap[i][j] == time-3) {
                      map[i][j] = '.';
                      
                      for (int d = 0; d < 4; d++) {
                          int nx = i + dx[d];
                          int ny = j + dy[d];
                          
                          if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                          if(tmap[nx][ny] == time-3) continue;
                          
                          map[nx][ny] = '.';
                      }
                  }
              }
          }
         cnt = 0;
      }

       time++;
   }

   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         cout << map[i][j];
      }
      cout << "\n";
   }
}
