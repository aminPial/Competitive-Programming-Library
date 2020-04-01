from collections import defaultdict
def solve():
    nodes = int(input())
    edge=int(input())
    graph = defaultdict(list)
    for _ in range(edge):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    visited = set()
    cc = [] # list to store connected components

    def dfs(temp, v):
        visited.add(v)
        temp.append(v) # the component list
        for i in graph[v]:
            if i not in visited:
                temp = dfs(temp, i)
        return temp

    def connectedComponents():
        for v in range(nodes):
            if v not in visited:
                temp = []
                cc.append(dfs(temp, v))
        # if you have to find the minimum connections needed to make them connected then do  ====> min_=len(cc)-1
        return cc # will return a list of connected components
    print(len(connectedComponents())-1)
if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
