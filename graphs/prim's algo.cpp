#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,vector<pair<int,int>>>g;
    
    void addEdge(int x,int y,int w){
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }
    void findMST(int src){
        map<int,int>cost;
        set<pair<int,int>>prim;
        map<int,bool>visited;
        for(auto node:g){// setting initial costs to not defined
            cost[node.first]=INT_MAX;
            visited[node.first]=false; //not visited any nodes yet
        }
        cost[src]=0;
        prim.insert(make_pair(0,src));
        while(!prim.empty()){
            auto f=*(prim.begin());
            prim.erase(prim.begin());
            int mincostnode=f.second;//extracting node with minimum cost
            visited[f.second]=true;
            
            //relaxing neighbour nodes
            for(auto x:g[mincostnode]){
                int nbr=x.first;
                int new_nbr_cost=x.second;
                if(new_nbr_cost<cost[nbr] && !visited[nbr]){
                    auto search=make_pair(nbr,cost[nbr]);
                    if(prim.find(search)!=prim.end())
                        prim.erase(search);
                    prim.insert(make_pair(new_nbr_cost,nbr));
                    cost[nbr]=new_nbr_cost;
                }
            }
        }
        for(auto x:cost)
            cout<<x.first<<"->"<<x.second<<endl;
    }
};

int main() {
	// your code goes here
	Graph g;
	g.addEdge(0,1,4);
	g.addEdge(0,2,6);
	g.addEdge(1,4,4);
	g.addEdge(1,3,3);
	g.addEdge(1,2,6);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(4,5,7);
	g.addEdge(3,5,3);
	g.findMST(0);
	return 0;
}
