from collections import defaultdict,deque
# same code as connected components but reverse it just
# the dependency sorting - DFS Approach
def DFS():
    visited = set()
    stack = []
    def dfs(node):
        visited.add(node)
        for child in graph[node]:
            if child not in visited:
                dfs(child)
        stack.append(node)  # stack.insert(0,node)

    # node num has to start from 0
    for node in range(nodes):
        if node not in visited:
            dfs(node)
    print(*stack[::-1])  # # stack.insert(0,node)

# InDegree Solution | Kahn's Algorithm
# we start with inDegree 0 (dependency 0)
def BFS():
    in_degree={node:0 for node in range(nodes)} # init with in degree 0
    queue=deque([])
    # to init inDegree and takes O(V+E) time
    for node in graph:
        for child in graph[node]:
            in_degree[child]+=1
    # initialize queue aka enqueue with dependency/inDegree=0
    for node in in_degree:
        if in_degree[node]==0:
            queue.append(node)
    topologicalOrdering=[]
    while queue:
        node=queue.popleft()
        # add to the topological ordering
        topologicalOrdering.append(node)
        # Iterate through all neighbouring nodes
        # of dequeued node u and decrease their in-degree
        # by 1
        for node in graph[node]:
            in_degree[node]-=1
            # if in Degree becomes zero then add to the queue
            if in_degree[node]==0:
                queue.append(node)
    if len(topologicalOrdering)!=nodes:
        exit("There exists a Cycle in the graph and thus the topological ordering is not possible")
    print(*topologicalOrdering)
    # 4 5 2 0 3 1

# print all the possible topological ordering
"""
In a Directed acyclic graph many a times we can have vertices which are unrelated to each other because of which we can order them in many ways. 
These various topological sorting is important in many cases, for example if some relative weight is also available between the vertices, which is to minimize then we
need to take care of relative ordering as well as their relative weight, which creates the need of checking through all possible topological ordering.
# We can go through all possible ordering via backtracking.
"""

if __name__ == '__main__':
    graph = defaultdict(list)
    nodes,edges=map(int,input().split())
    for _ in range(edges):
        frm,to=map(int,input().split())
        graph[frm].append(to)
    DFS()
    BFS()

"""
6 6
5 2
5 0
4 0
4 1
2 3
3 1

T.S(DFS) : 5 4 2 3 1 0
T.S(BFS) : 4 5 2 0 3 1

Cycle input
6 6
5 2
2 0
0 5
4 1
2 3
3 1

"""

"""
bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}

"""