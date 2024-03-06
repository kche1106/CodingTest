//
//  1347.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
   if (p1.first == p2.first) {
      return p1.second < p2.second;
   }
   return p1.first < p1.second;
}

int dx[4] = { 1, 0, -1, 0 };  //남, 서, 북, 동
int dy[4] = { 0, -1, 0, 1 };

int main() {
   int n;
   cin >> n;

   int dir = 0;
   vector<pair<int, int>> map;
   map.push_back({ 100, 100 });
   int size = 0;
   int startx = 100;
   int starty = 100;
   int endx = 100;
   int endy = 100;

   for (int i = 0; i < n; i++) {
      char c;
      cin >> c;

      if (c == 'R') {
         dir = (dir + 1) % 4;
      }
      else if (c == 'L') {
         dir = (dir + 3) % 4;
      }
      else {
         int prex = map[size].first;
         int prey = map[size].second;
         int nx = prex + dx[dir];
         int ny = prey + dy[dir];
          
         if (startx > nx) startx = nx;
         if (endx < nx) endx = nx;
         if (starty > ny) starty = ny;
         if (endy < ny) endy = ny;

         map.push_back({ nx, ny });
         size++;
      }
   }

   char res[201][201];
   memset(res, '#', sizeof(res));
   for (int i = 0; i < map.size(); i++) {
      res[map[i].first][map[i].second] = '.';
   }

   for (int i = startx; i <= endx; i++) {
      for (int j = starty; j <= endy; j++) {
         cout << res[i][j];
      }
      cout << "\n";
   }
}
