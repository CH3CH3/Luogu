#include "stdafx.h"
#include <iostream>
#include <cstring>
#define dyf main
#define maxn 200005 

using namespace std;
int num[15];
int tmp, rab, n, step;
void del_2xq() {
	int okay;
	for (int i = 1; i <= n; i++) {
		if (num[i] >= 2) {
			okay++;
			if (okay == 3) {
				num[i] -= 2;
				num[i - 1] -= 2;
				num[i - 2] -= 2;
				step++;
				for (int j = i + 1; j <= n; j++) {
					if (num[j] >= 2) num[i] = 0;
					else {
						i = j;
						okay = 0;
						break;
					}
				}
			}
		}
		else if (num[i] != 2) {
			okay = 0;
		}
	}
}
void del_1xq(){
	int okay;
	for (int i = 1; i <= n; i++) {
		if (num[i]) {
			okay++;
			if (okay == 5) {
				step++;
				num[i]--;
				num[i - 1]--;
				num[i - 2]--;
				num[i - 3]--;
				num[i - 4]--;
				for (int j = i + 1; j <= n; j++) {
					if (num) {
						num[j]--;
					}
					else {
						i = j;
						okay = 0;
						break;
					}
				}
			}
		}
		else {
			okay = 0;
		}
	}
}
void del_4xcad() {
	int okay;
	int singl[15];
	int doubl[15];
	int tripl[15];
	int fort[15];
	int singlcnt, doublcnt, fortcnt, triplcnt;
	for (int i = 1; i <= n; i++) {
		if (num[i] == 1) {
			singl[++singlcnt] = i;
		}
		else if (num[i] == 2) {
			doubl[++doublcnt] = i;
		}
		else if (num[i] == 4) {
			fort[++fortcnt] = i;
		}
		else if (num[i] == 3) {
			tripl[++triplcnt] = i;
		}
	}
	while (fortcnt--) {
		
	}
}
int dyf(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp >> rab;
		num[tmp]++;
	}

}
