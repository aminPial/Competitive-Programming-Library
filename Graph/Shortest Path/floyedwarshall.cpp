
// created by <xrssa> 
// floyd warshall for all-pair shortest path
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define NODES 1000
#define INF 9999999
// use Adjacent Matrix in ASP
vector< vector<int> > dist(NODES,vector<int>(NODES,INF));  // dp table for ASP and init with INF

void asp(int nodes){
    f(k,nodes)f(i,nodes)f(j,nodes) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,e;cin>>n>>e;
    while(e--) {
        int f,t,w;cin>>f>>t>>w;
        dist[f-1][f-1]=0; // distance from same node to same node is 0
        dist[t-1][t-1]=0; // same index
        dist[f-1][t-1]=w; // normal
    }
    asp(n);
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        int r=dist[x-1][y-1];
        if(r==INF) cout << -1 << "\n";
        else cout << r << "\n";
    }
    return 0;
}

// https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights

/* 

/* created by <xrssa> */
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define INF 99999
#define NODES 505


void asp(int n,vector<vector<int>> &dist){
    f(k,n)f(i,n)f(j,n) {dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                        dist[j][i]=dist[i][j];}
}

void solve(int tes){
    int n,e;cin>>n>>e;
    vector<vector<int>> dist(NODES, vector<int>(NODES,INF));
    while(e--){
        int x,y,w;scanf("%d %d %d",&x,&y,&w);
        dist[x][y]=w;
        dist[y][x]=w; // bidirectional
        dist[x][x]=0;
        dist[y][y]=0; // self distance is always 0
    }
    asp(n,dist);
    int my_city;scanf("%d",&my_city);
    printf("Case %d:\n",tes);
    f(i,n){
        int r=dist[my_city][i];
        if(r==INF) printf("Impossible\n");
        else printf("%d\n",r);
    }


}

int main()
{
    int q;scanf("%d",&q);
    f(i,q) solve(i+1);
    return 0;
}


*/