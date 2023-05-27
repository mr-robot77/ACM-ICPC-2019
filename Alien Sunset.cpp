#include<bits/stdc++.h>
using namespace std;
bool ap[200050];
int main()
{
    int n,hh;
    scanf("%d",&n);
    hh=0;
    int h,r,t;
    while(n--)
    {
        scanf("%d %d %d",&h,&r,&t);
        hh=max(h,hh);
        r+=1;
        t+=1;
        if(t<r)
        {
            for(int i=1;i<t;i++)
            {
                ap[i]=1;
            }
            t=t+h;
        }
        int cnt;
        for(int i=r+1;i<=t-1;i++)
        {
            cnt=0;
            while(i+h*cnt<=183000)
            {
                ap[i+h*cnt]=1;
                cnt++;
            }
        }
    }
    for(int i=1;i<=hh*1825;i++)
    {
        if(ap[i]==0)
        {
            printf("%d\n",i-1);
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}