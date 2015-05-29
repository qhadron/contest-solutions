#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

#define map unordered_map

typedef unsigned long long ull;

int N, s[6], found;

map<ull, bool> m;

ull reverse(ull  x) {
	ull  s = 31, res = x;
	for (x >>= 1; x; x >>= 1) {
		res <<= 1;
		res |= x & 1;
		--s;
	}
	return res << s;
}

inline bool check_hash(int* x) {
	ull forward = 0, back = 0, sum = 0, bity = 0;
	for (int k = 1; k < 2; ++k) {
		for (int i = 0; i < 6; ++i) {
			if (k == 1)sum += s[i];
			forward += (abs(s[(i + k) % 6] - s[i]) + 1)*s[i];
			back += (abs(s[(i + k) % 6] - s[i]) + 1)*s[(i + k) % 6];
			bity = (s[i] ^ (s[(i + k) % 6]));
			forward += bity;
			bity = (s[(i + k) % 6] ^ (s[i]));
			back += bity;
		}
	}
	forward += sum;
	back += sum;
	bity = (forward ^ ~reverse(back)) + (back ^ ~reverse(forward));
	return m[bity] ? true : !(m[bity] = true);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	while (N--) {
		for (int i = 0; i < 6; ++i)
			cin >> s[i];
		if (check_hash(s)) {
#ifndef _DEBUG
			cout << "Twin snowflakes found." << endl;
			return 0;
#else
			cout << "Found ";
			for (int i = 0; i < 6; ++i)
				cout << s[i] << " ";
			cout << endl;
#endif
		}
	}
	cout << "No two snowflakes are alike." << endl;
	return 0;
}

