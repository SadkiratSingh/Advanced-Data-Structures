#include <bits/stdc++.h>
using namespace std;


class Graph{
public:
    unordered_map<string,vector<pair<string,int>>>um;
    
    void addEdge(string A,string B,bool bidir,int weight){
        um[A].push_back(make_pair(B,weight));
        if(bidir){
            um[B].push_back(make_pair(A,weight));
        }
    }
    void printGraph(){
        for(auto x:um){
            cout<<"city"<<x.first<<"-->";
            for(auto y:x.second){
                cout<<y.first<<" "<<y.second<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	// your code goes here
	Graph g;
	g.addEdge("A","B",true,20);
	g.addEdge("B","D",true,40);
	g.addEdge("D","C",true,30);
	g.addEdge("C","A",true,10);
	g.addEdge("A","D",false,50);
	g.printGraph();
	return 0;
}
