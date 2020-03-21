/* created by <xrssa> */
// Prims Algorithm for finding MST in O(E x logE) where E in n edge process and proc is logE
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)

#define NODES 10000

map <int, vector < pair <int, int> > > graph;
priority_queue< pair<int, int> > pq;

bool visited[NODES]={false};
int vertex, edge;

int prim(int source){
    pq.push(make_pair(0, source)); // (weight, cost) // we have to negate as cpp has max-PQ and we need min-PQ
    int total_cost=0; // the total cost
    while(!pq.empty()){
        auto pair_=pq.top(); pq.pop();
        int node = pair_.second; int cost=-pair_.first; // - - = +

        if(visited[node])
            continue;
        visited[node]=true;
        total_cost+=cost;

        // now we  visit all the child nodes of the current node
        for(auto &children:graph[node]){
            if(visited[children.first])
                continue;
            pq.push(make_pair(-children.second,children.first)); // we negate as we need min-PQ // here children.second comes first
        }
    }
    return total_cost;
}

int main()
{
    cin >> vertex >> edge;
    f(i,edge){
        int to,from,weight; cin>>to>>from>>weight;
        graph[to].emplace_back(make_pair(from, weight));
        graph[from].emplace_back(make_pair(to,weight));
    }
    int source;cin>>source; // if source is given
    // cout << "MST is " << prim(source) << "\n";
    cout << prim(source) << "\n";
    return 0;
}

/*
 import heapq
class Graph:
    def __init__(self):
        self.graph={}
    def add_edge(self,p,c,w):
        if p not in self.graph.keys():
            self.graph[p]=[]
        if c not in self.graph.keys():
            self.graph[c]=[]
        self.graph[p].append([w,c])
        self.graph[c].append([w,p])
    def prim(self):
        visited=set()
        unvisited=[(0,1)] # (weight,source)
        t_cost=0
        while unvisited:
            cost,winner=heapq.heappop(unvisited)
            if winner not in visited:
                visited.add(winner);t_cost+=cost
                for cost,neighbour in self.graph[winner]:
                    if neighbour not in visited:
                        heapq.heappush(unvisited,(cost,neighbour))
        return t_cost
if __name__=="__main__":
     graph=Graph()
     n,e=map(int,input().split())
     for _ in range(e):
         p,c,w=map(int,input().split())
         graph.add_edge(p,c,w)
     print(graph.prim())



 */