//
//  11399.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/08/22.
//

#include <iostream>
using namespace std;

void temp(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    
    int arr[1000];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        arr[i] = x;
    }
    
    temp(arr, n);
    
    int sum = 0;
    int ans[1000];
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        ans[i] = sum;
    }
    
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
}
