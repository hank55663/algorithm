#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
pair<int,pii> S[2005][2005];
void add(int x,int y,int k,pii p){
    for(int i = x;i<2005;i+=i&-i){
        for(int j = y;j<2005;j+=j&-j){
          //  printf("%d %d %d\n",i,j,k);
            S[i][j]=max(S[i][j],mp(k,p));
        }
    }
}
pair<int,pii> query(int x,int y){
    pair<int,pii> res=mp(0,mp(0,0));
    for(int i = x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
          //  printf("%d %d %d\n",i,j,S[i][j].x);
            res=max(res,S[i][j]);
        }
    }
    return res;
}
int dp[1005][1005];
pii from[1005][1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1005],b[1005];
    map<int,int> M;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        M[a[i]];
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",&b[i]);
        M[b[i]];
    }
    M[-1000000000];
    int index=0;
    for(auto &it:M){
        it.y=++index;
    }
    int ans=0;
    pii ansi=mp(0,0);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=1;
                from[i][j]=mp(0,0);
                auto p=query(j-1,M[a[i]]-1);
                if(p.x+1>dp[i][j]){
                    dp[i][j]=p.x+1;
                    from[i][j]=p.y;
                }
              //  printf("%d %d %d %d\n",i,j,dp[i][j],M[a[i]]-1);
                if(dp[i][j]>ans){
                    ans=dp[i][j];
                    ansi=mp(i,j);
                }
            }
        }
        for(int j = 1;j<=m;j++){
            if(a[i]==b[j]){
                add(j,M[a[i]],dp[i][j],mp(i,j));
            }
        }
    }
    printf("%d\n",ans);
    vector<int> v;
    while(ansi!=mp(0,0)){
        v.pb(a[ansi.x]);
        ansi=from[ansi.x][ansi.y];
    }
    reverse(v.begin(),v.end());
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
    return 0;
}
/* 
1 3 6 10 15
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */