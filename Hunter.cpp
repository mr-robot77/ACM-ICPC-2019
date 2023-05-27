#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
struct node {
    double x, y;
}p[550];
int n;
double dp[550][550];

double dist(int a, int b)
{
    return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x) + (p[a].y-p[b].y)*(p[a].y-p[b].y));
}
double solve()
{
    dp[1][2] = dist(1, 2);
    for(int j = 3; j <= n; ++j) {
        for(int i = 1; i < j-1; ++i) {
            dp[i][j] = dp[i][j-1] + dist(j-1, j);
        }
        dp[j-1][j] = dp[1][j-1] + dist(1, j);
        for(int k = 1; k < j-1; ++k) {
            double q = dp[k][j-1] + dist(k, j);
            if(q < dp[j-1][j]) {
                dp[j-1][j] = q;
            }
        }
    }
    dp[n][n] = dp[n-1][n] + dist(n-1, n);
    //printf("%lf\n", dp[n][n]);
    return dp[n][n];
}
int main()
{
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        double ans = solve();
        printf("%.10lf\n", ans);
    }
    return 0;
}
