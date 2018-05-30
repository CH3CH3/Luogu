#include <stdio.h>
//#include <Windows.h>
#include <iostream>
#define dyf main
#define last point[i-1]
#define now point[i]
using namespace std;

int n, num;
int map[10005][10005];
struct node {
	int x, y;
}point[100005];
int dyf(){
	cin >> n;
	num = n * n;
	point[1].x = (n / 2 + 1);
	point[1].y = 1;
	map[point[1].x][point[1].y] = 1;
	for (int i = 2; i <= num; i++) {
		if (last.y == 1 && last.x != n) {
			point[i].y = n;
			point[i].x = last.x + 1;
			map[now.x][now.y] = i;
		}
		else if (last.y != 1 && last.x == n) {
			point[i].x = 1;
			point[i].y = last.y - 1;
			map[now.x][now.y] = i;
		}
		else if (last.y == 1 && last.x == n) {
			point[i].x = last.x;
			point[i].y = last.y + 1;
			map[now.x][now.y] = i;
		}
		else {
			if (map[last.x+1][last.y-1] == false) {
				point[i].x = last.x + 1;
				point[i].y = last.y - 1;
				map[now.x][now.y] = i;
			}
			else {
				point[i].x = last.x;
				point[i].y = last.y + 1;
				map[now.x][now.y] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[j][i] << " ";
		}
		cout << endl;
	}

	return 0;
}


