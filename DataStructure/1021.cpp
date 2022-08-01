//
//  1021.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/31.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {

    int n, l;
    cin >> n >> l;
    
    deque<int> d;
    
    for(int i = 1; i <= n; i++)
        d.push_back(i);
    
    int x, cnt = 0;
    
    for(int i = 0; i < l; i++) {
        cin >> x;
        
        int idx = 0;
        for(int i = 0; i < d.size(); i++) {
            if(d[i] == x) {
                idx = i;
                break;
            }
        }

        if(idx <= d.size() / 2) {
            while(true) {
                if(d.front() == x) {
                    d.pop_front();
                    break;
                }
                d.push_back(d.front());
                d.pop_front();
                cnt++;
            }
        }
        else {
            while(true) {
                if(d.front() == x) {
                    d.pop_front();
                    break;
                }
                d.push_front(d.back());
                d.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
