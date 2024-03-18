//
//  7490.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/18.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> ans;

void dfs(int i, int num, int val, int sign, string s) {
    if(i == n) {
        val += (num * sign);
        if(val == 0) cout << s << "\n";
    }
    else {
        dfs(i+1, num*10+(i+1), val, sign, s + " " + to_string(i+1));
        dfs(i+1, i+1, val+(sign*num), 1, s + "+" + to_string(i+1));
        dfs(i+1, i+1, val+(sign*num), -1, s + "-" + to_string(i+1));
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        dfs(1, 1, 0, 1, "1");
        cout << endl;
    }
}
