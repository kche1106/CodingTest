//
//  13305.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n;
   cin >> n;

   vector<long long> dist;
   for (int i = 0; i < n-1; i++) {
      long long d;
      cin >> d;
      dist.push_back(d);
   }

   vector<long long> cost;
   for (int i = 0; i < n; i++) {
      long long c;
      cin >> c;
      cost.push_back(c);
   }

   long long money = 0;
   long long oil = 0;
   long long pre_idx = 0;
   for (int i = 0; i < dist.size(); i++) {
      if (cost[pre_idx] < cost[i]) {
         money += cost[pre_idx] * dist[i];
      }
      else {
         money += cost[i] * dist[i];
         pre_idx = i;
      }
   }


   cout << money;
}
