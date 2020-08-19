#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    vector<int>* l;
    
    Graph(int V){
        this->V=V;
        this->l=new vector<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    void printGraph(Graph* g){
        for(int i=0;i<g->V;i++){
            cout<<"vertex"<<" "<<i<<"->";
            for(int j=0;j<g->l[i].size();j++){
                cout<<g->l[i][j]<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	// your code goes here
	int V=4;
	Graph* g=new Graph(V);
	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(1,0);
	g->addEdge(1,2);
	g->addEdge(2,0);
	g->addEdge(2,1);
	g->addEdge(2,3);
	g->addEdge(3,2);
	g->printGraph(g);
	return 0;
}
