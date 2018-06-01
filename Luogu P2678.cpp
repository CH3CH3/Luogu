#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 500010
#define dyf main
#define ulong unsigned long long

using namespace std;
int l, m, n, tot, ans;
int a[maxn];
bool judge(int x) {
	int i, now;
	i = 0;
	now = 0;
	tot = 0;
	while (i < n + 1) {
		i++;
		if (a[i] - a[now] < x) {
			tot++;
		}
		else {
			now = i;
		}
	}
	if (tot > m) return false;
	return true;
}
int dyf() {
	cin >> l >> n >> m;
	int le = 1;
	int ri = l;
	int mid;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = l;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (judge(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
