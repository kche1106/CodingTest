//
//  1863.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/28.
//

#include<iostream>
#include<stack>
using namespace std;

int main() {

   int n;
   cin >> n;

   int res = 0;
   stack<int> st;
   for (int i = 0; i <= n; i++) {
      int x, y;
      if (i != n) cin >> x >> y;
      else y = 0;

      while (!st.empty() && st.top() >= y) {
         if (st.top() > y) res++;
         st.pop();
      }
      st.push(y);
   }

   cout << res;
}
