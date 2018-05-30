#include <stdio.h> 
#include <iostream>
#include <cstring>
#define dyf main
#define maxn 200005 

using namespace std;
int head[maxn], cnt, sa;
int min(int x, int y) {
	if (x >= y) return y;
	return x;
}
struct node {
	int to, next;
}edge[maxn];
int n, ans = 0x3f3f3f, inx, tot;
int DFN[maxn], LOW[maxn], stack[maxn];
bool vis[maxn];
void add(int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
void tarjan(int x) {
	DFN[x] = LOW[x] = ++tot;
	stack[++inx] = x; 
	vis[x] = true;
	for (int i = head[x]; i != -1; i = edge[i].next) {
		if (!DFN[edge[i].to]) {
			tarjan(edge[i].to);
			LOW[x] = min(LOW[x], LOW[edge[i].to]);
		}
		else if (vis[edge[i].to])
			LOW[x] = min(LOW[x], DFN[edge[i].to]);
	}
	if (LOW[x] == DFN[x]) {
		sa = 0;
		do {
			sa++; vis[stack[inx--]] = false; 
		}while (x != stack[inx + 1]);
		if (sa == 2) {
			puts("2"); 
			exit(0); 
		}
		if (sa>1)ans = min(ans, sa);
	}
}
int dyf(){
	memset(head, -1, sizeof(head));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		add(i, tmp);
	}
	for (int i = 1; i <= n; i++) tarjan(i);
	cout << ans << endl;
    return 0;
}


