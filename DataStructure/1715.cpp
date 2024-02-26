#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> card;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		card.push(s);
	}

	int res = 0;
	for (int i = 0; i < n-1; i++) {
		int one = card.top();
		card.pop();
		int two = card.top();
		card.pop();

		cout << "o = " << one << " t = " << two << endl;

		int sum = one + two;
		res += sum;
		cout << "res = " << res << endl;
		card.push(sum);
	}

	cout << res;
}