//
//  11000.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/27.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n;
   cin >> n;

   priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;
   for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;

      v.push_back({a, b});  //end, start
   }
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    
    for(int i = 1; i < v.size(); i++) {
       
        int start = v[i].first;
        int end = v[i].second;
        pq.push(end);
       
        if(pq.top() <= start) {
            pq.pop();
        }
   }
    
   cout << pq.size();
}
