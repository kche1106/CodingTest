//
//  7682.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/28.
//

#include<iostream>
#include<vector>
using namespace std;


bool XWIN(vector<char> map[3]) {
   //x가 이기는 경우
   for (int i = 0; i < 3; i++) {
      if (map[i][0] == 'X' && map[i][1] == 'X' && map[i][2] == 'X') return true;
   }
   for (int i = 0; i < 3; i++) {
      if (map[0][i] == 'X' && map[1][i] == 'X' && map[2][i] == 'X') return true;
   }
   if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X') return true;
   if (map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X') return true;

   return false;
}

bool OWIN(vector<char> map[3]) {
   //O가 이기는 경우
   for (int i = 0; i < 3; i++) {
      if (map[i][0] == 'O' && map[i][1] == 'O' && map[i][2] == 'O') return true;
   }
   for (int i = 0; i < 3; i++) {
      if (map[0][i] == 'O' && map[1][i] == 'O' && map[2][i] == 'O') return true;
   }
   if (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O') return true;
   if (map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O') return true;

   return false;
}

int main() {
   while (true) {
      string s;
      cin >> s;
      if (s == "end") break;

      vector<char> map[3];
      int idx = 0;
      int xnum = 0, onum = 0;
      for (int i = 0; i < s.length(); i++) {
         if (s[i] == 'X') xnum++;
         else if (s[i] == 'O') onum++;
         map[idx].push_back(s[i]);
         if (i == 2 || i == 5) idx++;
      }

      bool xwin = XWIN(map);
      bool owin = OWIN(map);

      //cout << "X = " << xwin << " O = " << owin << endl;

      //x가 이긴 경우
      if (xwin && !owin && xnum == onum+1) {
         cout << "valid\n";
      }

      //y가 이긴 경우
      else if (owin && !xwin && xnum == onum) {
         cout << "valid\n";
      }

      //판이 가득찬 경우
      else if (xnum == 5 && onum == 4 && !xwin && !owin) {
         cout << "valid\n";
      }

      else {
         cout << "invalid\n";
      }
   }
}
