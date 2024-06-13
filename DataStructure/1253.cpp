//
//  1253.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() { 
    int n;
    cin >> n;

    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = n-1;
        int target = v[i];

        while(start < end) {
            int sum = v[start] + v[end];

            if(sum > target || i == end) {
                end -= 1;
            }
            else if(sum < target || i == start) {
                start += 1;
            } 
            else if (sum == target) {
                res++;
                break;
            }
        }
    }

    cout << res;
}