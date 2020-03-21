#include<bits/stdc++.h>
using namespace std;
 
#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int MAX = 505;
 
int P[MAX][MAX][20], a[MAX];
 
void buildSparseTable(int row,int n)
{
    for(int i=1; i<=n; i++)
        P[row][i][0] = a[i];
 
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
            P[row][i][j] = max(P[row][i][j-1], P[row][i+(1<<(j-1))][j-1]);
    }
}
int query(int row,int L, int R)
{
    int log = log2(R-L+1);
 
    return max(P[row][L][log], P[row][R - (1 << log) + 1][log]);
}
 
int main()
{
    int t,cas=1;
 
    scanf("%d",&t);
 
    while(t--)
    {
 
        int n,q,u,v,s;
 
        scanf("%d%d",&n,&q);
 
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&a[j]);
 
            buildSparseTable(i,n);
        }
 
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d%d%d",&u,&v,&s);
 
            int mx = 0;
 
            for(int i=u; i<=u+s-1; i++)
                mx = max(mx,query(i,v,v+s-1));
 
            printf("%d\n",mx);
        }
    }
}