//
//  19941.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
using namespace std;

int main() {
   int n, k;
   cin >> n >> k;

   char table[20001];
   for (int i = 0; i < n; i++) {
      cin >> table[i];
   }

   int res = 0;
   for (int i = 0; i < n; i++) {
      if (table[i] == 'P') {
         for (int j = i - k; j <= i + k; j++) {
            if (table[j] == 'H') {
               res++;
               table[j] = -1;
               break;
            }
         }
      }
   }

   cout << res;
}
