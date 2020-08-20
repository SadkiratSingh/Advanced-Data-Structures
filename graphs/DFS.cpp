#include <bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    map<T,vector<T>>um;
public:
    void addEdge(T x,T y){
        um[x].push_back(y);
        um[y].push_back(x);
    }
    void dfs_helper(T node,map<T,bool>& visited){
        visited[node]=true;
        cout<<node<<" ";
        for(T l:um[node]){
            if(visited[l]==false){
                dfs_helper(l,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        for(auto p:um){
            visited[p.first]=false;
        }
        dfs_helper(src,visited);
    }
};

int main() {
	// your code goes here
	Graph<int>g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.dfs(0);
	return 0;
}