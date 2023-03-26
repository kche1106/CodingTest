//
//  7568.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/03/26.
//

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    pair<int, int> arr[50];
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    int rank = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                rank++;
        }
        cout << rank << " ";
        rank = 1;
    }
}
        
