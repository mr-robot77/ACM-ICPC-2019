#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<cstdlib>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#define ll long long int
#define INF 0x3f3f3f3f
#define mod 1000000007
#define me(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node{
     char str;
     int pi;
 }s[1005];
 char str[1005];
 int a[10005],b[10005],c;
 bool cmp(node a,node b){
     if(a.str!=b.str) return a.str<b.str;
     return a.pi<b.pi;
 }
 int main(){
     scanf("%s",&str);
     int l=strlen(str);
     for(int i=0;i<l;i++){
         s[i].str=str[i];
         s[i].pi=i;
     }
     sort(s,s+l,cmp);
     c=0;
     int n[1005];
     for(int i=0;i<l;i++){
         n[s[i].pi]=i;
     }
     for(int i=0;i<l;i++){
         if(s[i].pi!=i){
             a[c]=i;
             b[c]=s[i].pi;
             c++;
             int pre=s[i].pi;
             int now=n[i];
             swap(s[now],s[i]);
             n[pre]=now;
         }
     }
     for(int i=c-1;i>=0;i--){
         printf("%d %d\n",b[i]+1,a[i]+1);
     }
     return 0;
 }
