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

## Motivation Behind Union-Find Problem.

### Kruskal’s Algorithm:
**Sort the edges in the given graph G by length and examine them from shortest to longest. Put each edge into the current forest if it doesn’t form a cycle with the edges chosen so far.**

The initial step takes time O(|E| log |E|) to sort. Then, for each edge, we need to test if it connects two different components. If it does, we will insert the edge, merging the two components into one; if it doesn’t (the two endpoints are in the same component), then we will skip this edge and go on to the next edge. So, to do this efficiently we need a data structure that can support the basic operations of (a) determining if two nodes are in the same component, and (b) merging two components together. This is the union-find problem.

### General setting of union find problem:
#### This has been demonstrated in https://github.com/SadkiratSingh/Advanced-Data-Structures/blob/master/disjoint%20sets/detect%20cycle.cpp
> The general setting for the union-find problem is that we are maintaining a collection of disjoint sets {S1, S2, . . . , Sk} over some universe, with the following operations:
> * MakeSet(x): create the set {x}.
> * Union(x, y): replace the set x is in (let’s call it S) and the set y is in (let’s call it S′) with the single set S ∪ S′.
> * Find(x): return the unique ID for the set containing x (this is just some representative element of this set).
> * Given these operations, we can implement Kruskal’s algorithm as follows. The sets Si will be the sets of vertices in the different trees in our forest. We begin with     MakeSet(v) for all vertices v (every vertex is in its own tree). When we consider some edge (v,w) in the algorithm, we just test whether Find(v) equals Find(w). If they are equal, it means that v and w are already in the same tree so we skip over the edge. If they are not equal, we insert the edge into our forest and perform a Union(v,w) operation. All together we will do |V | MakeSet operations, |V |−1 Unions, and 2|E| Find operations.

#### Motive is now to optimize our Union-Find Problem
##### Data Structure 1(list-based)
1. In this data structure, the sets will be just represented as linked lists: each element has a pointer to the next element in its list.
1. we will augment the list so that each element also has a pointer directly to head of its list.
1. The head of the list is the representative element.
We can now implement the operations as follows:
> * MakeSet(x): just set x->head=x. This takes constant time.
> * Find(x): just return x->head. Also takes constant time.
> * Union(x, y): To perform a union operation we merge the two lists together, and reset the head pointers on one of the lists to point to the head of the other. Let A be the  list containing x and B be the list containing y, with lengths L1 and L2 respectively. Then we can do this in time O(L1 + L2) by appending B onto the end of A as follows: We first walk down A to the end, and set the final next pointer to point to y->head. This takes time O(L1). Next we go to y->head and walk down B, resetting head pointers of
elements in B to point to x->head. This takes time O(L2). Can we reduce this to just O(L2)? Yes. Instead of appending B onto the end of A, we can just splice B into the middle of A, at x. I.e., let z=x->next, set x->next=y->head, then walk down B as above, and finally set the final next pointer of B to z. Can we reduce this to O(min(L1,L2))? Yes. Just store the length of each list in the head.Then compare and insert the shorter list into the middle of the longer one. Then update the length count to L1 + L2.
> * The above algorithm has total running time O(m + n log n)

##### Data Structure 2(tree-based)
1. This approach will further optimize the Union-Find problem and disjoint sets are mostly represented by trees as it will be discussed in this approach.
1. Instead of updating all the head pointers in list B (or whichever was shorter) when we perform a Union, we could do this in a lazy way, just pointing the head of B to the head of A and then waiting until we actually perform a find operation on some item x before updating its pointer.
1. This will decrease the cost of the Union operations but will increase the cost of Find operations because we may have to take multiple hops.
1. By doing this we no longer need the downward pointers: what we have in general is a collection of trees, with all links pointing up.
1. Rather than deciding which of the two heads (or roots) should be the new one based on the size of their sets, perhaps there is some other quantity that would give us better performance. In particular, it turns out we can do better by setting the new root based on which tree has larger RANK.
##### by implementing the two optimizations described above (lazy updates and union-by-rank), the total cost is bounded above by O(mlg∗ n), where lg∗ n is the number of times you need to take log2 until you get down to 1.
We can now implement the operations as follows:
> * Each element (node) will have two fields: a parent pointer that points to its parent in its tree (or itself if it is the root) and a rank, which is an integer used to determine which node becomes the new root in a Union operation.
> * MakeSet(x): set x’s rank to 0 and its parent pointer to itself. This takes constant time.
> * Find(x): starting from x, follow the parent pointers until you reach the root, updating x and all the nodes we pass over to point to the root. This is called PATH COMPRESSION. The running time for Find(x) is proportional to (original) distance of x to its root.
> * Union(x, y): Let Union(x, y) = Link(Find(x), Find(y)), where Link(root1,root2) behaves as follows. If the one of the roots has larger rank than the other, then that one becomes the new root, and the other (smaller rank) root has its parent pointer updated to point to it. If the two roots have equal rank, then one of them (arbitrarily) is picked to be the new root and its rank is increased by 1. This procedure is called UNION BY RANK.

##### Properties of Rank
###### 1. The rank of a node is the same as what the height of its subtree would be if we didn’t do path compression.
###### 2. if you take two trees of different heights and join them by making the root of the shorter tree into a child of the root of the taller tree, the heights do not change.
###### 3. if the trees were the same height, then the final tree will have its height increase by 1.
###### 4. If x is not a root node, then rank(x) < rank(parent(x)). This is because a node of rank k is created only by merging two roots of rank k – 1.
###### 5. If x is not a root, then rank(x) will never change again. This is because rank changes only for roots; a nonroot never becomes a root.
###### 6. If parent(x) changes, then rank(parent(x)) strictly increases. This is because the parent can change only for a root, so before linking parent(x) = x ; After x is linked-by-rank to new root r we have rank(r) > rank(x).
###### 7. Any root node of rank k has ≥ 2<sup>k</sup> nodes in its tree.
       Proof. ( by induction on k )
       * Base case: true for k = 0.
       * Inductive hypothesis: assume true for k – 1.
       * A node of rank k is created only by merging two roots of rank k – 1.
       * By inductive hypothesis, each subtree has ≥ 2^k – 1 nodes
       ⇒ resulting tree has ≥ 2^k nodes.
###### 8. The highest rank of a node is ≤ log<sub>2</sub>n
