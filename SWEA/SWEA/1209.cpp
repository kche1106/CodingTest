//
//  1209.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/12.
//

#include <iostream>
using namespace std;

int main() {
    for(int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        
        int arr[100][100];
        
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
        
        int max_sum = 0;
        for(int i = 0; i < 100; i++) {
            int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
            for(int j = 0; j < 100; j++) {
                sum1 += arr[i][j];
                sum2 += arr[j][i];
                if(i == j) sum3 += arr[i][j];
                if(i == 100-j) sum4 += arr[j][100-j];
            }
            max_sum = max(max_sum, sum1);
            max_sum = max(max_sum, sum2);
            max_sum = max(max_sum, sum3);
            max_sum = max(max_sum, sum4);
        }
        
        cout << "#" << i+1 << " " << max_sum << endl;
    }
}
