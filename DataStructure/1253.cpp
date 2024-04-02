//
//  1253.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/01.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> v;
    for(int i = 0; i < n; i++) {
        long long l;
        cin >> l;
        v.push_back(l);
    }
    sort(v.begin(), v.end());
    
    long long res = 0;
    
    for(int i = 0; i < n; i++) {
        
        int start = 0;
        int end = n-1;
        
        while(start < end) {
            if(end == i || v[start] + v[end] > v[i]) end = end - 1;
            else if(start == i || v[start] + v[end] < v[i]) start = start + 1;
            else if(v[start] + v[end] == v[i]) {
//                cout << v[i] << " start = " << start << " end = " << end << endl;
                res++;
                break;
            }
        }
    }
    
    cout << res;
}
/*
2
1 1000000000
 
3
0 -5 5
 */
