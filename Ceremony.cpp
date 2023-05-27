#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int h[maxn],n;
int main(){
    while(~scanf("%d",&n)){
        for(int i = 1; i <= n; ++i)
            scanf("%d",h+i);
        sort(h+1,h+n+1);
        int ret = n;
        for(int i = 1; i <= n; ++i)
            ret = min(ret,n - i + h[i]);
        printf("%d\n",ret);
    }
    return 0;
}
