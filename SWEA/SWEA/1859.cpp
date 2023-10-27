//
//  main.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
using namespace std;
int price[1000001];

int main() {
    int t, n;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n;
        
        for(int j = 0; j < n; j++) {
            cin >> price[j];
        }
        
        int max = price[n-1];
        long long sum = 0;
        for(int k = n-2; k >= 0; k--) {
            if(max < price[k]) max = price[k];
            else sum += max - price[k];
        }
        
        cout << "#" << i+1 << " " << sum << '\n';
    }
}
