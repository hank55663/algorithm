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
pii from[1005][1005];
int dp[1005][1005];
int main(){
    char a[1005],b[1005];
    scanf("%s %s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for(int i = 1 ; b[i]!=0;i++){
        dp[0][i]=i;
        from[0][i]=mp(0,i-1);
    }
    for(int i = 1;a[i]!=0;i++){
        dp[i][0]=i;
        from[i][0]=mp(i-1,0);
    }
    for(int i = 1;a[i]!=0;i++){
        for(int j = 1;b[j]!=0;j++){
            dp[i][j]=1e9;
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                from[i][j]=mp(i-1,j-1);
            }
            if(dp[i-1][j]+1<dp[i][j]){
                dp[i][j]=dp[i-1][j]+1;
                from[i][j]=mp(i-1,j);
            }
            if(dp[i][j-1]+1<dp[i][j]){
                dp[i][j]=dp[i][j-1]+1;
                from[i][j]=mp(i,j-1);
            }
        }
    }
    vector<char> v;
    pii now=mp(n,m);
    printf("%d\n",dp[n][m]);
    while(now!=mp(0,0)){
        if(from[now.x][now.y].x!=now.x){
            v.pb(a[now.x]);
        }
        else{
            v.pb(b[now.y]);
        }
        now=from[now.x][now.y];
    }
    reverse(v.begin(),v.end());
    for(auto it:v)
        printf("%c",it);
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