#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		// observation: x + x = 2x (power of two * x)
		// suppose y = 2x
		// y + y = 2y = 2(2x) = 4x (power of two * x)
		// conclusion: if 'k' is a power of 2, the answer is always yes
		// can always split k as the product of 2 factors (a power of 2 and an odd part)
		// let's write k = o * (2 ^ p)
		// it's enough to make all elements of 'a' divisible by 'o' and then just keep multiplying
		// them by 2 to make them divisible by 'k' as well
		
		// keep only the odd part of 'k', which we called 'o'
		while (k % 2 == 0) {
			k /= 2;
		}
		bool checker = true;
		for (int i = 0; i < n; i++) {
			checker &= (a[i] % k == 0);
		}
		cout << (checker ? "YES" : "NO") << '\n';
	}
	return 0;
}
