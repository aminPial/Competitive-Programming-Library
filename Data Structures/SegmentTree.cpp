#include<bits/stdc++.h>

#define MAX 100005 // 10**5 + 5
using namespace std;

int ara[MAX];
int tree[MAX*4];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]); // f()
}

int query(int node,int b,int e,int i, int j)
{
    if(i>e || j<b)
        return INT_MAX; // for sum return 0, min -> INT_MAX , max -> -INT_MAX
    if(b>=i && e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2); // f()
}

void update(int node,int b,int e, int i, int new_value)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]=new_value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,new_value);
    update(right,mid+1,e,i,new_value);
    tree[node]=min(tree[left],tree[right]); // f()
}

int main()
{
    // freopen("in.txt","r",stdin);
    // ///freopen("out.txt","w",stdout);
    // int n;
    // cin>>n;
    // for(int i=1; i<=n; i++)
    //     cin>>ara[i];
    // init(1,1,n);
    // cout<<query(1,1,n,1,4)<<endl;
    // update(1,1,n,2,0);
    // cout<<query(1,1,n,2,2)<<endl;
    // update(1,1,n,2,1);
    // cout<<query(1,1,n,2,3)<<endl;
    int n,q,l,r;
    int t;scanf("%d",&t);
    for(int ts=1;ts<=t;ts++){
        printf("Case %d:\n",ts);
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) cin>>ara[i]; // ara[i] i insert starts from (1 , <=n)
        init(1,1,n);
        while(q--){
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }

}