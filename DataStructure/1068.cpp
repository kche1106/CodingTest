//
//  1068.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/09.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[51];
// int visited[51];
int r;
int res;

void dfs(int node)
{

    if (v[node].size() == 0)
    {
        res++;
        return;
    }

    if (v[node].size() == 1 && v[node][0] == r)
    {
        res++;
        return;
    }

    for (int i = 0; i < v[node].size(); i++)
    {
        if (v[node][i] != r)
        {
            // visited[v[node][i]] = 1;
            dfs(v[node][i]);
        }
    }
}

int main()
{
    cin >> n;

    int root = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a == -1)
            root = i;
        else
            v[a].push_back(i);
    }

    cin >> r;

    if (r != root)
        dfs(root);

    cout << res;
}