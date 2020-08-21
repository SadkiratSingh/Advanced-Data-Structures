#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj,int i,int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool detectCycleHelper(vector<vector<int>>& adj,int curr,vector<int>vis){
    vis[curr]=1;
    for(int i=0;i<adj[curr].size();i++){
        int nbr=adj[curr][i];
        if(vis[nbr]==0){
            if(detectCycleHelper(adj,nbr,vis))
                return true;
        }
        else if(vis[nbr]==1)
            vis[nbr]=2;
        else
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj,int V){
    vector<int>visited(V,0);
    return detectCycleHelper(adj,0,visited);
}

void printGraph(vector<vector<int>>& adj,int V){
    for(int i=0;i<V;i++){
        cout<<i<<"-->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
}

int main() {
	// your code goes here
	int V=4;
	vector<vector<int>>adj(V);
	addEdge(adj,0,2);
	addEdge(adj,2,3);
	addEdge(adj,0,1);
	addEdge(adj,0,3);
	if(detectCycle(adj,V))
	    cout<<"cycle detected";
	else
	    cout<<"cycle not detected";
	return 0;
}
