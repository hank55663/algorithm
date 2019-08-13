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
int a[1005];
int dp[1005][1005];
int from[1005][1005];
struct node{
    node *l,*r;
    int a,b;
    int Max,Maxi;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0),Maxi(0){

    }
}*root[1005];
void pull(node *n){
    if(n->l->Max>n->r->Max){
        n->Max=n->l->Max;
        n->Maxi=n->l->Maxi;
    }
    else{
        n->Max=n->r->Max;
        n->Maxi=n->r->Maxi;
    }
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void revise(node *n,int x,int k,int i){
    if(n->a==n->b){
        if(k>n->Max){
            n->Max=k;
            n->Maxi=i;
        }
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        revise(n->l,x,k,i);
    }
    else{
        revise(n->r,x,k,i);
    }
    pull(n);
}
pii query(node *n,int l,int r){
    if(l>r){
        return mp(0,0);
    }
    if(n->a>=l&&n->b<=r){
        return mp(n->Max,n->Maxi);
    }
    if(n->b<l||n->a>r){
        return mp(0,0);
    }
    return max(query(n->l,l,r),query(n->r,l,r));
}
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]];
    }
    m[-1000000000];
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    for(int i = 1;i<=n;i++){
        root[i]=new node(1,index);
        build(root[i]);
    }
    int ans=1;
    pii ansi=mp(0,1);
    for(int i = 1;i<=n;i++){
        for(int j =1;j<i;j++){
            dp[j][i]=2;
            from[j][i]=0;
            pii p=query(root[j],1,prev(m.lower_bound(a[i]))->y);
            if(p.x>=2){
                dp[j][i]=p.x+1;
                from[j][i]=p.y;
            }
            revise(root[i],m[a[j]],dp[j][i],j);
            if(dp[j][i]>ans){
                ans=dp[j][i];
                ansi=mp(j,i);
            }
        }
        dp[0][i]=1;
        from[0][i]=0;
        revise(root[i],index,1,i);
    }
    printf("%d\n",ans);
    vector<int> v;
    while(ansi!=mp(0,0)){
        v.pb(a[ansi.y]);
        ansi.y=from[ansi.x][ansi.y];
        swap(ansi.x,ansi.y);
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