#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;++i)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL DP[25][8];
LL T[8][8] = {
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 1, 1, 2},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 0, 1, 1, 0, 0, 1, 1},
	{0, 1, 0, 1, 0, 1, 0, 2},
	{1, 1, 1, 2, 1, 1, 2, 3}
};
int B[25];
int m, n;
double x, y;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	F(n) {
		cin >> x >> y;
		B[int(x)] |= 1<<int(y);
	}
	DP[0][7] = 1;
	F(m) {
		Fi(j,8){
			if (j&B[i]) continue;
			Fi(k,8){
				if (!B[i] || (k&B[i]))
					DP[i+1][j|B[i]] += DP[i][k]*T[j][k];
			}
		}
	}
	cout << DP[m][7] << endl;
return 0;
}
