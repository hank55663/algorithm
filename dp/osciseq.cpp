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
struct node{
    node *l,*r;
    int a,b;
    int Max,Maxi;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0),Maxi(0){

    }
}*root[2];
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
    int a[100005];
    int ori[100005];
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]];
        ori[i]=a[i];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    root[0]=new node(1,index);
    root[1]=new node(1,index);
    build(root[0]);
    build(root[1]);
    int from[100005][2];
    int dp[100005][2];
    int ans=0;
    pii ansi;
    for(int i = 1;i<=n;i++){
        a[i]=m[a[i]];
        pii p=query(root[0],1,a[i]-1);
        dp[i][1]=p.x+1;
        from[i][1]=p.y;
        if(p.x+1>ans){
            ans=p.x+1;
            ansi=mp(i,1);
        }
        p=query(root[1],a[i]+1,index);
        if(p.x!=0){
            dp[i][0]=p.x+1;
            from[i][0]=p.y;
            revise(root[0],a[i],dp[i][0],i);
            if(p.x+1>ans){
                ans=p.x+1;
                ansi=mp(i,0);
            }
        }
        revise(root[1],a[i],dp[i][1],i);
    }
    printf("%d\n",ans);
    vector<int> v;
    while(ansi!=mp(0,0)){
        v.pb(ori[ansi.x]);
        ansi.x=from[ansi.x][ansi.y];
        ansi.y^=1;
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