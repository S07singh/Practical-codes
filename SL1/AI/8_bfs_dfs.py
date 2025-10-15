from collections import deque

# DFS recursive
def dfs(vertex, visited, graph):
    visited.add(vertex)
    print(vertex, end=' ')
    for neighbor in graph.get(vertex, []):
        if neighbor not in visited:
            dfs(neighbor, visited, graph)

# BFS using queue
def bfs(start, graph):
    visited = set([start])
    queue = deque([start])
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for neighbor in graph.get(v, []):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Build the graph once
graph = {}
n = int(input("Number of edges: "))

for _ in range(n):
    u, v = input("Edge (u v): ").split()
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []
    graph[u].append(v)
    graph[v].append(u)  # Undirected graph

start = input("Start vertex: ").strip()

if start not in graph:
    print("Start vertex not found in graph.")
else:
    while True:
        print("\nChoose traversal method:")
        print("a) DFS")
        print("b) BFS")
        print("c) Both")
        choice = input("Enter choice (a/b/c): ").strip().lower()

        if choice == 'a':
            print("\nDFS Traversal:")
            dfs(start, set(), graph)
        elif choice == 'b':
            print("\nBFS Traversal:")
            bfs(start, graph)
        elif choice == 'c':
            print("\nDFS Traversal:")
            dfs(start, set(), graph)
            print("\nBFS Traversal:")
            bfs(start, graph)
        else:
            print("Invalid choice.")

        cont = input("\nDo you want to try again (y/n)? ").strip().lower()
        if cont != 'y':
            print("Exiting program. Goodbye!")
            break

# Enter number of edges: 6
# Edge (u v): A B
# Edge (u v): A C
# Edge (u v): B D
# Edge (u v): B E
# Edge (u v): C F
# Edge (u v): E F
# Enter start vertex: A
