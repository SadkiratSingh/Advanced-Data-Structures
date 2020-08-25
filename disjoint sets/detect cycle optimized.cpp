#include <bits/stdc++.h>
using namespace std;

// representation of each vertex of graph
class Node{
public:
    int parent;
    int rank;
};

vector<Node>& make_set(vector<Node>& node_list,int V){
    for(int i=0;i<V;i++){
        node_list[i].parent=-1;
        node_list[i].rank=0;
    }
}

int Find(int v,vector<Node>& node_list){
    // perform find with path compression
    if(node_list[v].parent==-1)
        return v;
    else{
        node_list[v].parent=Find(node_list[v].parent,node_list);
        return node_list[v].parent;
    }
}

void Union(int p1,int p2,vector<Node>& node_list){
    // perform union by rank
    if(node_list[p1].rank>node_list[p2].rank)
        node_list[p2].parent=p1;
    else if(node_list[p1].rank<node_list[p2].rank)
         node_list[p1].parent=p2;
    else{
        node_list[p1].parent=p2;
        node_list[p2].rank+=1;
    }
}

bool isCyclic(vector<pair<int,int>>& edge_list,vector<Node>& node_list){
    // process for each edge
    for(auto pair:edge_list){
        int p1=Find(pair.first,node_list);
        int p2=Find(pair.second,node_list);
        if(p1==p2)
            return true;
        else 
            Union(p1,p2,node_list);
    }
    return false;
}

int main() {
	// your code goes here
	int V;
	int E;
	cin>>V;
	cin>>E;
	vector<pair<int,int>>edge_list;
	for(int i=0;i<E;i++){
	    int x,y;
	    cin>>x>>y;
	    edge_list.push_back(make_pair(x,y));
	}
	// let each vertex of graph be a set in itself
	vector<Node>node_list(V);
	make_set(node_list,V);
	
	// check for cycle
	if(isCyclic(edge_list,node_list))
	    cout<<"cycle detected";
	else
	    cout<<"no cycle detected";
	return 0;
}
