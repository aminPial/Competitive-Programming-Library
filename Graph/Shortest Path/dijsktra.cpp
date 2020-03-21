/* created by <xrssa> */
// #pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx")  //Enable AVX
// #include <x86intrin.h> //AVX/SSE Extensions
// dijsktra algorithm to find single shortest Path
// sol for https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// Time complexity O(E + VlogV) v*logV here logV is the priority queue pop push
#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define fa(elem,arr) for(auto &elem:arr)
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define mod             1000000007
#define all(a)           a.begin(),a.end()
#define INF 1e9
#define EPS 1e-6

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void dijsktra(){
    // same as bfs code
    map<int, vector< pair<int,int> > > graph;
    int n,e;cin>>n>>e;

    f(i,e){
        int f,t,w;cin>>f>>t>>w;
        // in question given "Given an undirected graph and a starting node"
        // but if we have directed node just deo f->t
        t--;f--;
        graph[f].emplace_back(make_pair(t,w));
        graph[t].emplace_back(make_pair(f,w));
    }
    int source;cin>>source;
    source--; // make it 0 index as given as 1 index

    vector<int> distance(n,INF); // initialize all distance with infifnity
    distance[source]=0; // here source must have to be zero indexed or make it zero indexed if not
    priority_queue<pair< int,int > > pq; // cpp gives max-PQ so we need to make it min by negation ??
    // todo: fix the max-pQ transformation to min_PQ ????????
    pq.push(make_pair(0, source)); // (weight, source) so that it gets sorted by the weight
    while(!pq.empty()){

        auto data=pq.top();
        int weight=data.first; int node=data.second;
        pq.pop();// delete from PQ
        // path relaxing
        // asking the question that which way we can optimize source-v or source-u+u-v
        // we put the parent node as the bridge and check if we can optimize the distance using the bridgee
        fa(elem,graph[node]){
            int child=elem.first; int cost_parent_child=elem.second;
            if (distance[node]+cost_parent_child < distance[child]){
                distance[child]= distance[node] + cost_parent_child;
                pq.push(make_pair(distance[child], child)); // we update the distance in PQ too
            }
        }
    }
    // distance from the source to all other nodes except the source node
    f(i,n){
        // 0 index based
        // if(i!=source) cout << " source -> " << i << " -> " << distance[i] << "\n";
        if(i!=source) {
            int distance_= distance[i]==INF ? -1:distance[i];
            cout << distance_ << " ";
        }
        }

    cout << "\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--) dijsktra();
    return 0;
}
