#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int from;
    int to;
    int weight;
    Edge(int from,int to,int weight){
        this->from=from;
        this->to=to;
        this->weight=weight;
    }
};

class Node{
public:
    int parent;
    int rank;
    Node(){
        parent=-1;
        rank=0;
    }
};

void make_set(vector<Node>& node_list,int V){
    for(int i=0;i<V;i++){
        Node n;
        node_list.push_back(n);
    }
}

int Find(int v,vector<Node>& node_list){
    if(node_list[v].parent==-1)
        return v;
    else{
        node_list[v].parent=Find(node_list[v].parent,node_list); //path compression
        return node_list[v].parent;
    }
}

void Union(int p1,int p2,vector<Node>& node_list){
    // union by rank
    if(node_list[p1].rank>node_list[p2].rank)
        node_list[p2].parent=p1;
    else if(node_list[p1].rank<node_list[p2].rank)
        node_list[p1].parent=p2;
    else{
        node_list[p1].parent=p2;
        node_list[p2].rank+=1;
    }
}

void Kruskal(vector<Edge>& edge_list,int V,int E,vector<Edge>& MST){
    // sort all edges
    sort(edge_list.begin(),edge_list.end(),[](Edge a,Edge b){
        return a.weight<b.weight;
    });// Expected Time complexity-->ElogE
    
    vector<Node>node_list;
    // make every node a set in itself;
    make_set(node_list,V);
    
    int i=0;
    int j=0;
    while(i<V-1 && j<E){
        int p1=Find(edge_list[j].from,node_list); //Expected time complexity-->LogV
        int p2=Find(edge_list[j].to,node_list);
        if(p1!=p2){
            MST.push_back(edge_list[j]); //create MST
            Union(p1,p2,node_list);
            i++;
        }
        j++;
    }
}

void printMST(vector<Edge>& MST){
    for(auto x:MST)
        cout<<x.from<<" "<<x.to<<" "<<x.weight<<endl;
}

int main() {
	// your code goes here
	int V;
	int E;
	cin>>V;
	cin>>E;
	vector<Edge>edge_list; //undirected graph representation
	for(int i=0;i<E;i++){
	    int x,y,w;
	    cin>>x>>y>>w;
	    Edge e(x,y,w); //weighted edge
	    edge_list.push_back(e);
	}
	vector<Edge>MST;// minimum spanning tree
	Kruskal(edge_list,V,E,MST);
    printMST(MST);	
	return 0;
}
