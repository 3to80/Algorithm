
####Problem
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is give


n as graph.




graph.length = N, and j != i is in the list graph[i] exactly once, if and onl


y if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.


#####Note

- - -
####Solution
s, e에 대해 
d = Dijkstra(s, e) 
가장 작은 d 를 구하기 
 
 
 
 
- - - 
####Analysis
Time complexity

Space complexity
- - -
####Discussion

        DP = [[float('inf')] * nodeNum for x in range(nodeNum)]
            

- - -
####Reference

