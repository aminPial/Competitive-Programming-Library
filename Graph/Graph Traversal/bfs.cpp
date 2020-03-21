#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)

void bfs(){
    int nodes=1e6;
    int source=0; // source
    map<int ,vector<int> > graph;
    vector < int > node_parents(nodes);
    set<int> visited;
    queue<tuple<int,string >> q;
    q.push(make_pair(source,""));
    visited.insert(source);
    while(!q.empty()){
        auto tupes=q.front();
        int node = get<0> (tupes);
        string path=get<1> (tupes);
        q.pop(); // use q.back() for dfs
        cout << node << " ";
        for(int child:graph[node]){
            if (visited.count(child)==0){
                q.push((make_pair(child,path+to_string(child))));
                visited.insert(child);
                node_parents[child]=node;
            }
        }
    }

}

bool sortbysec(const tuple<int,int,int>& a,
               const tuple<int,int,int>& b){
    return get<2>(a) < get<2>(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    return 0;
}
