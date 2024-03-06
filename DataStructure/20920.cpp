//
//  20920.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &v1, const pair<string, int> &v2) {
   if (v1.second == v2.second) {
      if (v1.first.length() == v2.first.length()) {
         return v1.first < v2.first;
      }
      else return v1.first.length() > v2.first.length();
   }
   else return v1.second > v2.second;
}

int main() {

   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int n, m;
   cin >> n >> m;

   unordered_map<string, int> word;
   for (int i = 0; i < n; i++) {
      string w;
      cin >> w;
      if (w.length() >= m) word[w]++;
   }

   vector<pair<string, int>> v(word.begin(), word.end());

   sort(v.begin(), v.end(), cmp);

   for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << "\n";
   }
}
