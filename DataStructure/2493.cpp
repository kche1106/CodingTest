//
//  2493.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<pair<int, int>> st;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        if(st.empty()) {
            st.push({x, i});
            ans.push_back(0);
        }
        else {
            if(st.top().first < x) {
                while(true) {
                    if(st.empty() || st.top().first > x) break;
                    st.pop();
                }
                if(st.empty()) ans.push_back(0);
                else ans.push_back(st.top().second);
                
                st.push({x, i});
            }
            else if(st.top().first > x) {
                ans.push_back(st.top().second);
                st.push({x, i});
            }
        }
    }
    
    for(auto a : ans) {
        cout << a << " ";
    }
}
