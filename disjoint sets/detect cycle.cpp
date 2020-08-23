#include <bits/stdc++.h>
using namespace std;

int Find(int node,vector<int>& dsuf){
    if(dsuf[node]==-1)
        return node;
    else
        return Find(dsuf[node],dsuf);
}

void Union(int p1,int p2,vector<int>& dsuf){
    dsuf[p1]=p2;
}

bool containsCycle(vector<pair<int,int>>& graph,vector<int>& dsuf){
    for(auto edge:graph){
        int n1=edge.first;
        int n2=edge.second;
        int Pn1=Find(n1,dsuf);// finding absolute parent
        int Pn2=Find(n2,dsuf);
        
        if(Pn1==Pn2) //common absolute parent
            return true;
        else Union(Pn1,Pn2,dsuf);// union of two sets
    }
    return false;
}

int main() {
	// your code goes here
	int E; //no. of edges
	int V; //no. of vertices
	cin>>E;
	cin>>V;
	vector<int>dsuf(V,-1);//signifying each vertex is a disjoint set
	
	vector<pair<int,int>>graph;//representing graph by edge list
	for(int i=0;i<E;i++){
	    int x,y;
	    cin>>x>>y;
	    graph.push_back(make_pair(x,y));
	}
	if(containsCycle(graph,dsuf)) //call the func to detect cycle
	    cout<<"cycle detected";
	else
	    cout<<"no cycle detected";
	
	return 0;
}
