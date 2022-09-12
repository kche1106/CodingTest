//
//  15649.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/09/12.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool visited[9];


void func(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(!visited[i]){
            visited[i] = true;
            arr[count] = i;
            func(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    
    func(0);
}
