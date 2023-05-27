#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 300;
struct arc{
    int to,flow,next;
    arc(int x = 0,int y = 0,int z = -1){
        to = x;
        flow = y;
        next = z;
    }
}e[maxn*maxn*10];
int head[maxn],d[maxn],cur[maxn],tot,S,T;
void add(int u,int v,int flow){
    e[tot] = arc(v,flow,head[u]);
    head[u] = tot++;
    e[tot] = arc(u,0,head[v]);
    head[v] = tot++;
}
bool bfs(){
    queue<int>q;
    memset(d,-1,sizeof(d));
    d[S] = 0;
    q.push(S);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i; i = e[i].next){
            if(e[i].flow && d[e[i].to] == -1){
                d[e[i].to] = d[u] + 1;
                q.push(e[i].to);
            }
        }
    }
    return d[T] > -1;
}
int dfs(int u,int low){
    if(u == T) return low;
    int tmp = 0,a;
    for(int &i = cur[u]; ~i; i = e[i].next){
        if(e[i].flow && d[e[i].to] == d[u] + 1&&(a=dfs(e[i].to,min(low,e[i].flow)))){
            e[i].flow -= a;
            e[i^1].flow += a;
            low -= a;
            tmp += a;
            if(!low) break;
        }
    }
    if(!tmp) d[u] = -1;
    return tmp;
}
int solve(){
    int ans = 0;
    while(bfs()){
        memcpy(cur,head,sizeof(head));
        ans += dfs(S,INF);
    }
    return ans;
}
int main(){
    int ks,n,m,k;
    double x,y;
    scanf("%d",&ks);
    while(ks--){
        scanf("%d %d %d",&n,&m,&k);
        memset(head,-1,sizeof(head));
        for(int i = tot = 0; i < k; ++i){
            scanf("%lf %lf",&x,&y);
            add((int)x,n+(int)y,1);
        }
        S = n + m;
        T = S + 1;
        for(int i = 0; i < n; ++i)
            add(S,i,1);
        for(int i = 0; i < m; ++i)
            add(i+n,T,1);
        printf("%d\n",solve());
    }
    return 0;
}
