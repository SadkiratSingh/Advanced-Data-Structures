# Advanced-Data-Structures

## Difference between Djikstra and Prim

* #### Prim's algorithm constructs a minimum spanning tree for the graph, which is a tree that connects all nodes in the graph and has the least total cost among all trees that connect all the nodes.MSTs are useful, for example, if you wanted to physically wire up the nodes in the graph to provide electricity to them at the least total cost. It doesn't matter that the path length between two nodes might not be optimal, since all you care about is the fact that they're connected.
----------------------------
* #### Given a connected, undirected graph G, a shortest-path tree rooted at vertex v is a spanning tree T of G, such that the path distance from root v to any other vertex u in T is the shortest path distance from v to u in G.Djikstra's algorithm constructs a shortest path tree starting from some source node.This is useful, for example, if you wanted to build a road network that made it as efficient as possible for everyone to get to some major important landmark. However, the shortest path tree is not guaranteed to be a minimum spanning tree, and the sum of the costs on the edges of a shortest-path tree can be much larger than the cost of an MST.
----------------------------
* #### Another important difference concerns what types of graphs the algorithms work on. Prim's algorithm works on undirected graphs only, since the concept of an MST assumes that graphs are inherently undirected. (There is something called a "minimum spanning arborescence" for directed graphs, but algorithms to find them are much more complicated). Dijkstra's algorithm will work fine on directed graphs, since shortest path trees can indeed be directed. Additionally, Dijkstra's algorithm does not necessarily yield the correct solution in graphs containing negative edge weights, while Prim's algorithm can handle this.
----------------------------

## Prim and Dijkstra algorithms are almost the same, except for the "relax function".

Prim:

MST-PRIM (G, w, r) {
    for each key ∈ G.V
        u.key = ∞
        u.parent = NIL
    r.key = 0
    Q = G.V

    while (Q ≠ ø)
        u = Extract-Min(Q)
        for each v ∈ G.Adj[u]
            if (v ∈ Q)
                alt = w(u,v)    <== relax function, Pay attention here
                if alt < v.key
                    v.parent = u
                    v.key = alt
}
Dijkstra:

Dijkstra (G, w, r) {
    for each key ∈ G.V
        u.key = ∞
        u.parent = NIL
    r.key = 0
    Q = G.V

    while (Q ≠ ø)
        u = Extract-Min(Q)
        for each v ∈ G.Adj[u]
            if (v ∈ Q)
                alt = w(u,v) + u.key  <== relax function, Pay attention here
                if alt < v.key
                    v.parent = u
                    v.key = alt
}

> * The Prim, which searches for the minimum spanning tree, only cares about the minimum of the total edges cover all the vertices. The relax function is alt = w(u,v)
> * The Dijkstra, which searches for the minimum path length, so it cares about the edge accumulation. The relax function is alt = w(u,v) + u.key

## Time Complexity in detecting cycle in graphs using disjoint sets concept->
#### O(EXV).This is because we process every edge in the edge list. Further in each cycle of procession we check whether the nodes making the edge belong to different or same sets.


