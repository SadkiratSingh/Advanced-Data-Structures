#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,vector<int>>um;
public:
    void addEdge(int x,int y){
        um[x].push_back(y);
        um[y].push_back(x);
    }
    
    bool detectCycleUtil(int node,map<int,bool>& visited,int par){
        visited[node]=true;
        for(auto x:um[node]){
            if(visited[x]==false){
                bool got_cycle=detectCycleUtil(x,visited,node);
                if(got_cycle)
                    return got_cycle;
            }
            else if(x!=par)
                return true;
        }
        return false;
    }
    
    bool detectCycle(){
        map<int,bool>visited;
        for(auto x:um)
            visited[x.first]=false;
        return detectCycleUtil(1,visited,-1);
    }
    
    void printGraph(){
        for(auto x:um){
            cout<<x.first<<"-->";
            for(auto y:um[x.first]){
                cout<<y<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	// your code goes here
	Graph g;
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(1,3);
	g.addEdge(3,5);
	if(g.detectCycle())
	    cout<<"cycle detected";
	else
	    cout<<"no cycle detected";
	return 0;
}