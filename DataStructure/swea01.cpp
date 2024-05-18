#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> player(n);
        for (int i = 0; i < n; i++)
        {
            cin >> player[i];
        }
        sort(player.begin(), player.end());

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> team;
            team.push_back(player[i]);

            for (int j = 0; j < n; j++) {
                if(i == j) continue;

                bool flag = true;
                for (int h = 0; h < team.size(); h++)
                {
                    if (abs(team[h] - player[j]) > k)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    team.push_back(player[j]);
                }
            }

            if (res < team.size())
                res = team.size();
        }

        cout << res << "\n";
    }
}