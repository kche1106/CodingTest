//
//  2240.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int t, w;
vector<int> order;
vector<int> change;
vector<int> visited;
vector<int> vw;
int ans;
int res;

void count() {
    int idx = 0;
    int tree = 1;
    for (int i = 0; i < order.size(); i++) {
//        cout << "i = " << i << " ";
        if (i == vw[idx]) {
//            cout << "if" << " ";
            res += 1;
            tree = order[i];
            idx += 1;
        }
        else {
//            cout << "else" << " ";
            if(tree == order[i]) res += 1;
        }
//        cout << "tree = " << tree << endl;
    }
//    cout << "res = " << res << endl;
}

void switching() {
    if (vw.size() == w) {
        
//        for (auto a : vw) cout << a << " ";
//        cout << endl;
        
        count();
//        vw.clear();
        
        //        cout << res << " ";
        if(ans < res) ans = res;
        res = 0;
        
        return;
    }

    for (int i = 0; i < change.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            vw.push_back(change[i]);
            switching();
            vw.erase(vw.end() - 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> t >> w;
    
    int pre = 1;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        order.push_back(num);
        if (pre != num) {
            change.push_back(i);
            visited.push_back(0);
        }
        pre = num;
    }
    
    
//    for (auto a : change) cout << a << " ";
//    cout << endl;
    
    switching();
    
    cout << ans;
}
