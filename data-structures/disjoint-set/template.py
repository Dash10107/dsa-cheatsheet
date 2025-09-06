class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.components = n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        
        self.components -= 1
        return True
    
    def connected(self, x, y):
        return self.find(x) == self.find(y)
    
    def count_components(self):
        return self.components

class UnionFindWithPathCompression:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        
        if self.size[px] < self.size[py]:
            px, py = py, px
        
        self.parent[py] = px
        self.size[px] += self.size[py]

# Common union-find operations
def find_circle_num(is_connected):
    """Number of connected components in an undirected graph (LeetCode 547)."""
    n = len(is_connected)
    uf = UnionFind(n)
    for i in range(n):
        for j in range(i + 1, n):
            if is_connected[i][j]:
                uf.union(i, j)
    return uf.count_components()

def find_redundant_connection(edges):
    """Find the redundant edge that creates a cycle (LeetCode 684)."""
    n = len(edges)
    uf = UnionFind(n + 1)
    for u, v in edges:
        if not uf.union(u - 1, v - 1):
            return [u, v]
    return []

def accounts_merge(accounts):
    """Merge accounts with common emails (LeetCode 721)."""
    from collections import defaultdict
    email_to_name = {}
    graph = defaultdict(list)
    for acc in accounts:
        name = acc[0]
        for email in acc[1:]:
            email_to_name[email] = name
            graph[acc[1]].append(email)
            graph[email].append(acc[1])
    seen = set()
    res = []
    for email in graph:
        if email not in seen:
            stack = [email]
            seen.add(email)
            component = []
            while stack:
                node = stack.pop()
                component.append(node)
                for nei in graph[node]:
                    if nei not in seen:
                        seen.add(nei)
                        stack.append(nei)
            res.append([email_to_name[email]] + sorted(set(component)))
    return res

def valid_tree(n, edges):
    """Check if edges form a valid tree (LeetCode 261)."""
    if len(edges) != n - 1:
        return False
    uf = UnionFind(n)
    for u, v in edges:
        if not uf.union(u, v):
            return False
    return uf.count_components() == 1

def calc_equation(equations, values, queries):
    """Evaluate division equations (LeetCode 399)."""
    from collections import defaultdict
    graph = defaultdict(list)
    for (a, b), val in zip(equations, values):
        graph[a].append((b, val))
        graph[b].append((a, 1 / val))
    def dfs(x, y, visited):
        if x == y:
            return 1.0
        visited.add(x)
        for nei, val in graph[x]:
            if nei not in visited:
                res = dfs(nei, y, visited)
                if res != -1:
                    return res * val
        return -1
    res = []
    for x, y in queries:
        if x not in graph or y not in graph:
            res.append(-1.0)
        elif x == y:
            res.append(1.0)
        else:
            res.append(dfs(x, y, set()) if dfs(x, y, set()) != -1 else -1.0)
    return res

def equations_possible(equations):
    """Check if equations are possible (LeetCode 990)."""
    uf = UnionFind(26)
    for eq in equations:
        if eq[1:3] == '==':
            uf.union(ord(eq[0]) - ord('a'), ord(eq[3]) - ord('a'))
    for eq in equations:
        if eq[1:3] == '!=':
            if uf.find(ord(eq[0]) - ord('a')) == uf.find(ord(eq[3]) - ord('a')):
                return False
    return True
