#include <iostream>
#include <vector>
using namespace std;
int l, c, N, ans;
vector<int> nums;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> c;
		if (c == 0)
			nums.pop_back();
		else
			nums.push_back(c);
	}
	for (int i = 0; i < nums.size(); ++i)
		ans += nums[i];
	cout << ans << endl;
}