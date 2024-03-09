//
//  6294.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/08.
//

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> score;
    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;
        score.push_back(s);
    }
    
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        
        double sum = 0;
        for(int j = a-1; j <= b-1; j++) {
            sum += score[j];
        }
        printf("%.2f\n", sum / (b-a+1));
    }
}
