//
//  6288.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int main() {
    int w, n;  //무게
    cin >> w >> n;
    
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int m, p;
        cin >> m >> p;
        v.push_back({m, p});  //무게, 가격
    }
    sort(v.begin(), v.end(), cmp);
    
    int weight = 0;
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        if(weight == w) break;

        if(weight + v[i].first > w) {
            sum += v[i].second * (w - weight);
            weight = w;
        }
        else {
            sum += v[i].first * v[i].second;
            weight += v[i].first;
        }
        
//        cout << sum << " " << weight << endl;
    }
    
    cout << sum;
}
