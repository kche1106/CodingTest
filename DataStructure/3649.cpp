//
//  3649.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int x;
    while(cin >> x) {
        
        int n;  //레고 개수
        cin >> n;
        
        vector<int> lego;
        for(int i = 0; i < n; i++) {
            int l;
            cin >> l;
            lego.push_back(l);
        }
        sort(lego.begin(), lego.end());
                
        x = x * 10000000;
        int start = 0;
        int end = n-1;
        int l1 = -1, l2 = -1, sub = 0;
        while(start < end) {
            if(lego[start] + lego[end] > x) end = end - 1;
            else if(lego[start] + lego[end] < x) start = start + 1;
            else {
                if(lego[end] - lego[start] >= sub) {
                    sub = lego[end] - lego[start];
                    l1 = lego[start];
                    l2 = lego[end];
                }
                start+=1;
                end-=1;
            }
        }
        
        if(l1 == -1 && l2 == -1 && sub == 0) cout << "danger\n";
        else cout << "yes " << l1 << " " << l2 << "\n";
    }
}
/*
 20
 4
 100000000
 100000000
 1
 99999999
 
 2
 2
 1
 1
 */
